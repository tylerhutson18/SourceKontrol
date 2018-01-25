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
    
    
    // gets current directory of work
    myProcess.start( "pwd" );
    String sOutput = myProcess.readAllProcessOutput();
    Logger::outputDebugString( sOutput );
    
    // change label text based on child process
    statusMessage.setText("Current directory: " + sOutput, dontSendNotification);
    addAndMakeVisible(statusMessage);
    
    addAndMakeVisible(customCommitMsg);
    customCommitMsg.setEditable(true);
    customCommitMsg.setColour(Label::backgroundColourId, Colours::lightgrey);
    customCommitMsg.addListener(this);
    //commitMessage = customCommitMsg.getTextValue();
    
    // set gui size
    //setSize (400, 300);
    setSize(600, 450);
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
    //myHyperLinkButton.setBounds(x + 100, y, w + 90, h);
    statusMessage.setBounds(x + 100, y + 70, w + 300, h + 100);
    customCommitMsg.setBounds(x + 100, y, w + 50, h - 15);
}


void SourceKontrolAudioProcessorEditor::buttonClicked(Button* button)
{
    
    // check if github repo
    // git rev-parse 2> /dev/null; [ $? == 0 ] && echo 1
    
    // change this if you want a different commit message
    commitMessage = "audio commit";
    
    if (button == &commitButton) {
        
        // command to execute commit
        gitAdd.start("git add .");
        // gitCommit.start("git commit -m \"making a commit\"");
        gitCommit.start("git commit -m \"" + commitMessage + "\"");
    
        String commitOutput = gitCommit.readAllProcessOutput();
        Logger::outputDebugString( commitOutput );
        
        // change label text based on child process
        statusMessage.setText("Committing: " + commitOutput, dontSendNotification);
        
        commitButton.setButtonText("Committed");
        
        // reset button text
        
        

    } else if (button == &pullButton) {
        
        // command to execute pull
        gitPull.start("git pull");
        
        String pullOutput = gitPull.readAllProcessOutput();
        Logger::outputDebugString( pullOutput );
        
        // change label text based on child process
        statusMessage.setText("Pulling: " + pullOutput, dontSendNotification);
        
        pullButton.setButtonText("Pulled");

    } else if (button == &pushButton) {
        
        // command to execute push
        gitPush.start("git push");
        
        String pushOutput = gitPush.readAllProcessOutput();
        Logger::outputDebugString( pushOutput );
        
        // change label text based on child process
        statusMessage.setText("Pushing: " + pushOutput, dontSendNotification);
        
        pushButton.setButtonText("Pushed");
    }
}

void SourceKontrolAudioProcessorEditor::labelTextChanged(Label* label)
{
    if (label == &customCommitMsg) {
        
    }
}

