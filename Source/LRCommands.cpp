/*
  ==============================================================================

    LRCommands.cpp
    Created: 31 Jul 2015 10:21:12pm
    Author:  Parth

  ==============================================================================
*/

#include "LRCommands.h"

/*
Adjustment
"Temperature",
"Tint",
"Exposure",
"Highlights", 	(controls Recovery in PV2003 and PV2010)
"Shadows", 	(controls Fill Light in PV2003 and PV2010)
"Brightness", (no effect unless in PV2003 or PV2010)
"Contrast",
"Whites", 	(no effect in PV2003 and PV2010)
"Blacks",
"Clarity",
"Vibrance",
"Saturation",

tonePanel = {
"ParametricDarks",
"ParametricLights",
"ParametricShadows",
"ParametricHighlights",
"ParametricShadowSplit",
"ParametricMidtoneSplit",
"ParametricHighlightSplit",
}

mixerPanel = {
-- HSL / Color
"SaturationAdjustmentRed",
"SaturationAdjustmentOrange",
"SaturationAdjustmentYellow",
"SaturationAdjustmentGreen",
"SaturationAdjustmentAqua",
"SaturationAdjustmentBlue",
"SaturationAdjustmentPurple",
"SaturationAdjustmentMagenta",
"HueAdjustmentRed",
"HueAdjustmentOrange",
"HueAdjustmentYellow",
"HueAdjustmentGreen",
"HueAdjustmentAqua",
"HueAdjustmentBlue",
"HueAdjustmentPurple",
"HueAdjustmentMagenta",
"LuminanceAdjustmentRed",
"LuminanceAdjustmentOrange",
"LuminanceAdjustmentYellow",
"LuminanceAdjustmentGreen",
"LuminanceAdjustmentAqua",
"LuminanceAdjustmentBlue",
"LuminanceAdjustmentPurple",
"LuminanceAdjustmentMagenta",
-- B & W
"GrayMixerRed",
"GrayMixerOrange",
"GrayMixerYellow",
"GrayMixerGreen",
"GrayMixerAqua",
"GrayMixerBlue",
"GrayMixerPurple",
"GrayMixerMagenta",
}

splitToningPanel = {
"SplitToningShadowHue",
"SplitToningShadowSaturation",
"SplitToningHighlightHue",
"SplitToningHighlightSaturation",
"SplitToningBalance",
}

detailPanel = {
"Sharpness",
"SharpenRadius",
"SharpenDetail",
"SharpenEdgeMasking",
"LuminanceSmoothing",
"LuminanceNoiseReductionDetail",
"LuminanceNoiseReductionContrast",
"ColorNoiseReduction",
"ColorNoiseReductionDetail",
"ColorNoiseReductionSmoothness",
}

effectsPanel = {
-- Dehaze
"Dehaze",
-- Post-Crop Vignetting
"PostCropVignetteAmount",
"PostCropVignetteMidpoint",
"PostCropVignetteFeather",
"PostCropVignetteRoundness",
"PostCropVignetteStyle",
"PostCropVignetteHighlightContrast",
-- Grain
"GrainAmount",
"GrainSize",
"GrainFrequency",
}

lensCorrectionsPanel = {
-- Profile
"LensProfileDistortionScale",
"LensProfileChromaticAberrationScale",
"LensProfileVignettingScale",
"LensManualDistortionAmount",
-- Color
"DefringePurpleAmount",
"DefringePurpleHueLo",
"DefringePurpleHueHi",
"DefringeGreenAmount",
"DefringeGreenHueLo",
"DefringeGreenHueHi",
-- Manual Perspective
"PerspectiveVertical",
"PerspectiveHorizontal",
"PerspectiveRotate",
"PerspectiveScale",
"PerspectiveAspect",
"PerspectiveUpright",
}

calibratePanel = {
"ShadowTint",
"RedHue",
"RedSaturation",
"GreenHue",
"GreenSaturation",
"BlueHue",
"BlueSaturation",
}

*/

const std::vector<String> LRCommandList::AdjustmentStringList = {
    "Temperature",
    "Tint",
    "Exposure",
    "Highlights",
    "Shadows",
    "Contrast",
    "Whites",
    "Blacks",
    "Clarity",
    "Vibrance",
    "Saturation",
};

const std::vector<String> LRCommandList::ToneStringList = {
    "Parametric Darks",
    "Parametric Lights",
    "Parametric Shadows",
    "Parametric Highlights",
    "Parametric Shadow Split",
    "Parametric Midtone Split",
    "Parametric Highlight Split",
};

const std::vector<String> LRCommandList::MixerStringList = {
    // Colour
    "Saturation Adjustment Red",
    "Saturation Adjustment Orange",
    "Saturation Adjustment Yellow",
    "Saturation Adjustment Green",
    "Saturation Adjustment Aqua",
    "Saturation Adjustment Blue",
    "Saturation Adjustment Purple",
    "Saturation Adjustment Magenta",
    "Hue Adjustment Red",
    "Hue Adjustment Orange",
    "Hue Adjustment Yellow",
    "Hue Adjustment Green",
    "Hue Adjustment Aqua",
    "Hue Adjustment Blue",
    "Hue Adjustment Purple",
    "Hue Adjustment Magenta",
    "Luminance Adjustment Red",
    "Luminance Adjustment Orange",
    "Luminance Adjustment Yellow",
    "Luminance Adjustment Green",
    "Luminance Adjustment Aqua",
    "Luminance Adjustment Blue",
    "Luminance Adjustment Purple",
    "Luminance Adjustment Magenta",
    // B & W
    "Gray Mixer Red",
    "Gray Mixer Orange",
    "Gray Mixer Yellow",
    "Gray Mixer Green",
    "Gray Mixer Aqua",
    "Gray Mixer Blue",
    "Gray Mixer Purple",
    "Gray Mixer Magenta",
};

const std::vector<String> LRCommandList::LRStringList = {
    "Unmapped",
    /* Adjust */
    "Temperature",
    "Tint",
    "Exposure",
    "Highlights",
    "Shadows",
    "Contrast",
    "Whites",
    "Blacks",
    "Clarity",
    "Vibrance",
    "Saturation",
    /* Tone*/
    "ParametricDarks",
    "ParametricLights",
    "ParametricShadows",
    "ParametricHighlights",
    "ParametricShadowSplit",
    "ParametricMidtoneSplit",
    "ParametricHighlightSplit",
    /* Mixer */
    "SaturationAdjustmentRed",
    "SaturationAdjustmentOrange",
    "SaturationAdjustmentYellow",
    "SaturationAdjustmentGreen",
    "SaturationAdjustmentAqua",
    "SaturationAdjustmentBlue",
    "SaturationAdjustmentPurple",
    "SaturationAdjustmentMagenta",
    "HueAdjustmentRed",
    "HueAdjustmentOrange",
    "HueAdjustmentYellow",
    "HueAdjustmentGreen",
    "HueAdjustmentAqua",
    "HueAdjustmentBlue",
    "HueAdjustmentPurple",
    "HueAdjustmentMagenta",
    "LuminanceAdjustmentRed",
    "LuminanceAdjustmentOrange",
    "LuminanceAdjustmentYellow",
    "LuminanceAdjustmentGreen",
    "LuminanceAdjustmentAqua",
    "LuminanceAdjustmentBlue",
    "LuminanceAdjustmentPurple",
    "LuminanceAdjustmentMagenta",
    "GrayMixerRed",
    "GrayMixerOrange",
    "GrayMixerYellow",
    "GrayMixerGreen",
    "GrayMixerAqua",
    "GrayMixerBlue",
    "GrayMixerPurple",
    "GrayMixerMagenta",
};