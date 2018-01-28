# SourceKontrol

This is a project to try to incorporate source control in a Digital Audio Workstation through a VST plug-in interface for simplified collaboration.

It is also required that Command Line Tools be installed to allow the plug-in to communicate with GitHub.

The plug-in will check upon loading whether you're in an initialized repository. When switching between projects, make sure you close out of all others and reload your current project.

## Get Started

To get started with this plug-in, you will need to set up a GitHub repository for your project. 
(If you are unfamiliar with this process, look [here](https://help.github.com/articles/create-a-repo/).) This is where your files and changes will be recorded. [Clone](https://services.github.com/on-demand/github-cli/clone-repo-cli) that repository. When you begin your project, save the first edits of your project in that folder location. 

Download/save the VST plug-in in the root directory into your VST folder location.

Load the plug-in on to a track and open it. At the bottom, your current directory should be displayed. If this is not your repo folder location that you cloned, you haven't saved your project in the proper location. Once the plug-in displays the correct directory, everything should work fine.

When collaborating with other people, PULL first, reload the project, then you can make your changes and COMMIT them with a custom commit message (ex: "Added vocals"). Once you're done, click PUSH and your changes will be recorded in your project repo.
