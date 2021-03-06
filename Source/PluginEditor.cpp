
#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SourceKontrolAudioProcessorEditor::SourceKontrolAudioProcessorEditor (SourceKontrolAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    
    // buttons
    pullButton.setButtonText("Pull");
    addAndMakeVisible(pullButton);
    pullButton.addListener(this);
    
    commitButton.setButtonText("Commit");
    addAndMakeVisible(commitButton);
    commitButton.addListener(this);
    
    pushButton.setButtonText("Push");
    addAndMakeVisible(pushButton);
    pushButton.addListener(this);
    
    
    // hyperlink button
    projectRepoURL = URL(gitAudioRepo);
    projectRepoButton.setURL(projectRepoURL);
    projectRepoButton.setButtonText("Project");
    addAndMakeVisible(projectRepoButton);
    
    
    readmeURL = URL(gitReadMe);
    readmeButton.setURL(readmeURL);
    readmeButton.setButtonText("Help");
    addAndMakeVisible(readmeButton);
    
    
    // start child process: validate folder repo
    isGitRepoProc.start("git ls-remote");
    String isGitRepoOutput = isGitRepoProc.readAllProcessOutput();

    // start child process: get current directory
    getCurrDirProc.start("pwd");
    String currDirectory = getCurrDirProc.readAllProcessOutput();
    
    // change status message depending on repo status
    if (!isGitRepoOutput.contains("fatal")) {
        statusMessage.setText("Valid repo location. Current directory: " + currDirectory, dontSendNotification);
        addAndMakeVisible(statusMessage);
    } else {
        statusMessage.setText("Error: Folder has not been linked to git: " + currDirectory, dontSendNotification);
        addAndMakeVisible(statusMessage);
    }
    
    
    // custom commit message setup with default
    customCommitMsgLabel.setText("Committing audio.", dontSendNotification);
    customCommitMsgLabel.setColour(Label::backgroundColourId, Colours::dimgrey);
    customCommitMsgLabel.setEditable(true);
    customCommitMsgLabel.addListener(this);     // may not need this
    addAndMakeVisible(customCommitMsgLabel);
    
    
    // set gui size
    setSize(500, 400);
}

SourceKontrolAudioProcessorEditor::~SourceKontrolAudioProcessorEditor()
{
}

//==============================================================================
void SourceKontrolAudioProcessorEditor::paint (Graphics& g)
{
    //g.fillAll (Colours::white);
    g.fillAll(getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    
    //g.setColour (Colours::black);
    g.setColour (Colours::whitesmoke);
    g.setFont (22.0f);
    g.drawFittedText ("SourceKontrol", getLocalBounds(), Justification::centredTop, 1);
}

void SourceKontrolAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..

    int x = 50; int y = 60; int w = 80; int h = 50;
    
    pullButton.setBounds(x, y, w, h);
    commitButton.setBounds(x, y + 75, w, h);
    pushButton.setBounds(x, y + 150, w, h);
    projectRepoButton.setBounds(x + 120, y, w + 90, h);
    readmeButton.setBounds(x + 310, y - 60, w + 90, h);
    statusMessage.setBounds(x, y + 200, w + 300, h + 100);
    customCommitMsgLabel.setBounds(x + 120, y + 75, w + 100, h - 15);
}


void SourceKontrolAudioProcessorEditor::buttonClicked(Button* button)
{
    
    if (button == &pullButton) {
        
        gitPull();
        
    } else if (button == &commitButton) {
        
        // update custom commit message
        defCommitMsg = customCommitMsgLabel.getText();
        gitCommit();
        
    } else if (button == &pushButton) {
        
        gitPush();
        
    }
}


// Git methods
void SourceKontrolAudioProcessorEditor::gitPull()
{
    // start child process: pull files
    gitPullProc.start("git pull");
    
    String pullOutput = gitPullProc.readAllProcessOutput();
    Logger::outputDebugString(pullOutput);
    
    // change label text based on child process
    statusMessage.setText("Pulling: " + pullOutput, dontSendNotification);
    
    // update button UI
    pullButton.setButtonText("Pulled");
}

void SourceKontrolAudioProcessorEditor::gitCommit()
{
    // start child process: add files
    gitAddProc.start("git add .");
    
    // start child process: commit files
    gitCommitProc.start("git commit -m \"" + defCommitMsg + "\"");
    
    String commitOutput = gitCommitProc.readAllProcessOutput();
    Logger::outputDebugString(commitOutput);
    
    // change label text based on child process
    statusMessage.setText("Committing: " + commitOutput, dontSendNotification);
    
    // update button UI
    commitButton.setButtonText("Committed");
}

void SourceKontrolAudioProcessorEditor::gitPush()
{
    // start child process: push files
    gitPushProc.start("git push");
    
    String pushOutput = gitPushProc.readAllProcessOutput();
    Logger::outputDebugString(pushOutput);
    
    // change label text based on child process
    statusMessage.setText("Pushing: " + pushOutput, dontSendNotification);
    
    // update button UI
    pushButton.setButtonText("Pushed");
}

void SourceKontrolAudioProcessorEditor::labelTextChanged(Label* label)
{
    if (label == &customCommitMsgLabel) {
        // do something
    }
}

