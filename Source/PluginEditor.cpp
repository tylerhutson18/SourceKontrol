/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <iostream>
#include <stdlib.h>


//==============================================================================
SourceKontrolAudioProcessorEditor::SourceKontrolAudioProcessorEditor (SourceKontrolAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    // buttons
    commitButton.setButtonText("Commit");
    addAndMakeVisible(commitButton);
    commitButton.addListener(this);
    
    pullButton.setButtonText("Pull");
    addAndMakeVisible(pullButton);
    pullButton.addListener(this);
    
    pushButton.setButtonText("Push");
    addAndMakeVisible(pushButton);
    pushButton.addListener(this);
    
    
    // hyperlink button
    myURL = URL("https://github.com/tylerhutson18/SourceKontrol");
    myHyperLinkButton.setURL(myURL);
    myHyperLinkButton.setButtonText("Repo");
    addAndMakeVisible(myHyperLinkButton);
    
    // start child process to execute commands
    // gets current directory of work
    myProcess.start( "pwd" );
    String sOutput = myProcess.readAllProcessOutput();
    Logger::outputDebugString( sOutput );
    
    // change label text based on child process
    workingDirectory.setText("Current directory: " + sOutput, dontSendNotification);
    addAndMakeVisible(workingDirectory);
    
    
    
    // set gui size
    setSize (400, 300);
}

SourceKontrolAudioProcessorEditor::~SourceKontrolAudioProcessorEditor()
{
}

//==============================================================================
void SourceKontrolAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::white);

    g.setColour (Colours::black);
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
    workingDirectory.setBounds(x + 150, y + 80, w + 120, h);
}


void SourceKontrolAudioProcessorEditor::buttonClicked(Button* button)
{
    if (button == &commitButton) {
        commitButton.setButtonText("Committed");
        gitCommit.start("git commit -m \"making a commit\"");
        String commitOutput = myProcess.readAllProcessOutput();
        Logger::outputDebugString( commitOutput );
        
        // change label text based on child process
        workingDirectory.setText("Committing: " + commitOutput, dontSendNotification);

    } else if (button == &pullButton) {
        gitPull.start("git pull");
        pullButton.setButtonText("Pulled");
        String pullOutput = myProcess.readAllProcessOutput();
        Logger::outputDebugString( pullOutput );
        
        // change label text based on child process
        workingDirectory.setText("Pulling: " + pullOutput, dontSendNotification);

    } else if (button == &pushButton) {
        gitPush.start("git push");
        pushButton.setButtonText("Pushed");
        
        String pushOutput = myProcess.readAllProcessOutput();
        Logger::outputDebugString( pushOutput );
        
        // change label text based on child process
        workingDirectory.setText("Pushing: " + pushOutput, dontSendNotification);
    }
}
