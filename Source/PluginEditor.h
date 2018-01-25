/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#ifndef PLUGINEDITOR_H_INCLUDED
#define PLUGINEDITOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class SourceKontrolAudioProcessorEditor  : public AudioProcessorEditor, public Button::Listener
{
public:
    SourceKontrolAudioProcessorEditor (SourceKontrolAudioProcessor&);
    ~SourceKontrolAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void buttonClicked(Button* button) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SourceKontrolAudioProcessor& processor;

    TextButton commitButton;
    TextButton pullButton;
    TextButton pushButton;
    
    URL myURL;
    HyperlinkButton myHyperLinkButton;
    
    ChildProcess myProcess;     // process to execute commands
    ChildProcess gitPull;
    ChildProcess gitCommit;
    ChildProcess gitPush;
    
    Label workingDirectory;    // for getting/displaying current directory
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SourceKontrolAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
