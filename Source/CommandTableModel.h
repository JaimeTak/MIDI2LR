#ifndef COMMANDTABLEMODEL_H
#define COMMANDTABLEMODEL_H

#include <vector>
#include "../JuceLibraryCode/JuceHeader.h"
#include "CommandMap.h"
#include "CommandMenu.h"

class CommandTableModel : public TableListBoxModel
{
public:
    CommandTableModel();

    // TableListBoxModel overrides
    virtual int getNumRows() override;
    virtual void paintRowBackground (Graphics &, int rowNumber, int width, int height, bool rowIsSelected) override;
    virtual void paintCell (Graphics &, int rowNumber, int columnId, int width, int height, bool rowIsSelected) override;
    virtual Component *refreshComponentForCell (int rowNumber, int columnId, bool isRowSelected, Component *existingComponentToUpdate) override;

    void addRow(int midi_channel, int midi_data, bool isCC);
    void removeRow(int row);
    void removeAllRows();
    void buildFromXml(XmlElement *elem);

    int getRowForMessage(int midi_channel, int midi_data, bool isCC);
private:
    int _rows;

    std::vector<MIDI_Message> _commands;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CommandTableModel)
};

#endif