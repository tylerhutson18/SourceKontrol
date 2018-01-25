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
class SourceKontrolAudioProcessorEditor  : public AudioProcessorEditor, public Button::Listener, public Label::Listener
{
public:
    SourceKontrolAudioProcessorEditor (SourceKontrolAudioProcessor&);
    ~SourceKontrolAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void buttonClicked(Button* button) override;
    void labelTextChanged(Label* label) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SourceKontrolAudioProcessor& processor;

    // buttons
    TextButton commitButton;
    TextButton pullButton;
    TextButton pushButton;
    
    HyperlinkButton myHyperLinkButton;
    URL myURL;
    
    
    // processes to execute commands
    ChildProcess myProcess;
    ChildProcess gitPull;
    ChildProcess gitAdd;
    ChildProcess gitCommit;
    ChildProcess gitPush;
    
    // for getting/displaying current status
    Label statusMessage;
    Label customCommitMsg;
    
    String commitMessage;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SourceKontrolAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
