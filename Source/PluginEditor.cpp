/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
StereoPannerAudioProcessorEditor::StereoPannerAudioProcessorEditor (StereoPannerAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 300);

	//Slider example

	// these define the parameters of our slider object
	gui_Slider1.setSliderStyle(Slider::LinearBarVertical);
	gui_Slider1.setRange(0.0, 127.0, 1.0);
	gui_Slider1.setTextBoxStyle(Slider::NoTextBox, false, 90, 0);
	gui_Slider1.setPopupDisplayEnabled(true, this);
	gui_Slider1.setTextValueSuffix("text bubble");
	gui_Slider1.setValue(1.0);

	// this function adds the slider to the editor
	addAndMakeVisible(&gui_Slider1);

	//add the listener to the slider
	gui_Slider1.addListener(this);




}

StereoPannerAudioProcessorEditor::~StereoPannerAudioProcessorEditor()
{
}

//==============================================================================
void StereoPannerAudioProcessorEditor::paint (Graphics& g)
{

	//Hello World example

	//Fill the whole window
    g.fillAll (Colours::white);

	//Set current drawing colour
    g.setColour (Colours::black);

	//Set font
    g.setFont (15.0f);

	//Draw text to screen
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);


	//Draw Waveform
	DrawWaveform(g);


}

void StereoPannerAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

	//Slider example
	
	// sets the position and size of the slider with arguments (x, y, width, height)
	gui_Slider1.setBounds(40, 30, 20, getHeight() - 60);


}

//Listeners

//Example Slider
void StereoPannerAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	processor.gui_Slider1 = gui_Slider1.getValue();



}


void StereoPannerAudioProcessorEditor::DrawWaveform(Graphics& g)
{

	if (processor.gui_Slider1 >= 50.0)
	{
		   g.setColour(Colours::green);
	}
	else { g.setColour(Colours::blue); }


	g.drawLine(10, 300, 590, 300, 5);
}
