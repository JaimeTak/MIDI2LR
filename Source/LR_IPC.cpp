/*
  ==============================================================================

    LR_IPC.cpp
    Created: 2 Aug 2015 12:27:47am
    Author:  Parth

  ==============================================================================
*/

#include "LR_IPC.h"
#include "CommandMap.h"
#include "LRCommands.h"

const int LR_IPC::LR_PORT = 58763;

LR_IPC& LR_IPC::getInstance()
{
    static LR_IPC instance;
    return instance;
}

LR_IPC::LR_IPC() : InterprocessConnection()
{
    MIDIProcessor::getInstance().addMIDICommandListener(this);
    startTimer(1000);
}

void LR_IPC::shutdown()
{
    stopTimer();
    disconnect();
}

void LR_IPC::timerCallback()
{
    if (!isConnected())
    {
        connectToSocket("127.0.0.1", LR_PORT, 100);
        DBG("Connecting");
    }
}

void LR_IPC::addListener(LRConnectionListener *listener)
{
    _listeners.addIfNotAlreadyThere(listener);
}

void LR_IPC::connectionMade()
{
    for (auto listener : _listeners)
        listener->connected();
}

void LR_IPC::connectionLost()
{
    for (auto listener : _listeners)
        listener->disconnected();
}

void LR_IPC::messageReceived(const MemoryBlock& msg)
{

}

void LR_IPC::handleAsyncUpdate()
{
    if (!isConnected()) return;

    String command = _commandToSend + String::formatted(" %d\n", _valueToSend);
    getSocket()->write(command.getCharPointer(), command.length());
}

void LR_IPC::handleMidiCC(int midiChannel, int controller, int value)
{
    MIDI_Message cc(midiChannel, controller, true);

    if (CommandMap::getInstance().getCommandforMessage(cc) == 0) 
        return;

    _commandToSend = LRCommandList::LRStringList[(int)CommandMap::getInstance().getCommandforMessage(cc)];
    _valueToSend = value;
    handleAsyncUpdate();
}

void LR_IPC::handleMidiNote(int midiChannel, int note)
{
    MIDI_Message note_msg(midiChannel, note, false);

    if (CommandMap::getInstance().getCommandforMessage(note_msg) == 0)
        return;

    _commandToSend = LRCommandList::LRStringList[CommandMap::getInstance().getCommandforMessage(note_msg)];
    _valueToSend = 127;
    handleAsyncUpdate();
}