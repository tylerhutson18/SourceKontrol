/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SourceKontrolAudioProcessorEditor::SourceKontrolAudioProcessorEditor (SourceKontrolAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    myButton.setButtonText("Commit");
    addAndMakeVisible(myButton);
    myButton.addListener(this);
    
    
    URL myURL = URL("https://www.github.com");
    myHyperLinkButton.setURL(myURL);
    myHyperLinkButton.setButtonText("Click me.");
    
    addAndMakeVisible(myHyperLinkButton);
    
    setSize (400, 300);
}

SourceKontrolAudioProcessorEditor::~SourceKontrolAudioProcessorEditor()
{
}

//==============================================================================
void SourceKontrolAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::black);

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("SourceKontrol", getLocalBounds(), Justification::centredTop, 1);
}

void SourceKontrolAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    int w = 80; int h = 50; int x = 40; int y = 60;
    
    myButton.setBounds(x, y, w, h);
    myHyperLinkButton.setBounds(x + 100, y, w + 90, h);
}


void SourceKontrolAudioProcessorEditor::buttonClicked(Button* button)
{
    if (button == &myButton) {
        myButton.setButtonText("Committed");
        std::cout << "i should be printing?";
        system("ls");
    }
}
