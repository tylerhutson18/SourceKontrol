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
    
    commitButton.setButtonText("Commit");
    addAndMakeVisible(commitButton);
    commitButton.addListener(this);
    
    pullButton.setButtonText("Pull");
    addAndMakeVisible(pullButton);
    pullButton.addListener(this);
    
    pushButton.setButtonText("Push");
    addAndMakeVisible(pushButton);
    pushButton.addListener(this);
    
    
    
    myURL = URL("https://github.com/tylerhutson18/SourceKontrol");
    myHyperLinkButton.setURL(myURL);
    myHyperLinkButton.setButtonText("Repo");
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
    g.setFont (22.0f);
    g.drawFittedText ("SourceKontrol", getLocalBounds(), Justification::centredTop, 1);
}

void SourceKontrolAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    int w = 80; int h = 50; int x = 40; int y = 60;
    
    pullButton.setBounds(x, y, w, h);
    commitButton.setBounds(x, y + 75, w, h);
    pushButton.setBounds(x, y + 150, w, h);
    myHyperLinkButton.setBounds(x + 100, y, w + 90, h);
}


void SourceKontrolAudioProcessorEditor::buttonClicked(Button* button)
{
    if (button == &commitButton) {
        commitButton.setButtonText("Committed");
    } else if (button == &pullButton) {
        pullButton.setButtonText("Pulled");
    } else if (button == &pushButton) {
        pushButton.setButtonText("Pushed");
    }
}
