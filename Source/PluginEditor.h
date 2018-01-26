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
    
    void gitPull();
    void gitCommit();
    void gitPush();

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SourceKontrolAudioProcessor& processor;

    
    // buttons
    TextButton pullButton;
    TextButton commitButton;
    TextButton pushButton;
    
    HyperlinkButton projectRepoButton;
    URL projectRepoURL;
    
    
    // processes to execute commands
    ChildProcess getCurrDir;
    ChildProcess gitPullProc;
    ChildProcess gitAddProc;
    ChildProcess gitCommitProc;
    ChildProcess gitPushProc;
    
    // for getting/displaying current status
    Label statusMessage;
    Label customCommitMsgLabel;
    
    String commitMessage;
    
    // hyperlink button links
    String gitSrcRepo = "https://github.com/tylerhutson18/SourceKontrol";
    String gitAudioRepo = "https://github.com/tylerhutson18/SourceKontrol_Audio";
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SourceKontrolAudioProcessorEditor)
};


#endif  // PLUGINEDITOR_H_INCLUDED
