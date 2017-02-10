--PROTOTPYING README--

The custom Max 7 patch file in this folder can host VSTs, and is intended
to be used as a prototyping environment, as well as a debugging environment.

The Max patch uses a custom .bat file enable faster workflow 
when rebuilding a VST project in Visual Studio. 
Visual Studio projects may only be rebuilt when the 
most reccently built DLL is not in use with a host program
i.e when Max7 does not have the VST or Dll loaded into it's virtual address space.  

The Max patch simply uses a bang message to firstly load the blank DLL file in place of 
any currently loaded VST plugin, and subsequently launches the .bat file to delete the previous 
DLL file, ensuring Visual Studio can rebuild. 

Where the Max patch is used without the use of a custom .bat file,
the user may have to manually delete the dll from Visual Studio 
build output folder before they can succesfully rebuild their project.
Alternatively, one might try researching how to fully unload a VST from Max 7's
[vst~] object. 



To fully utilize this this Max patch, follow these steps (Windows only!)

1) Create a new .txt file

2) Edit the text file with the following, ensuring that you customize the parts wrapped in $ signs:
**Note that you can delete the 3rd line if you are not building x64 bit versions of your VST

start
cd C:\Users\$YourWindowsLogonName$\$FolderWhereYourProjectIs$\$YourVstName$\Builds\VisualStudio2013\Debug
cd C:\Users\$YourWindowsLogonName$\$ParentFolderOfYourProjectFolder$\$YourVstName$\Builds\VisualStudio2013\x64\Debug
del YourVstName.dll

3) Save the .txt file, and rename it "deleteDLL.bat" (this is the name Max will look for)

4) Move or copy this file to the C:/ folder (this is where Max will try to find deleteDLL.bat)

5) Finally, navigate to your builds output folder (this is where your VST file is created when you compile 
   your code), create a new blank .txt file, save it, and rename it "blankDLL.dll". 

OR

Simply copy and paste the blankDLL file included in this repository to your builds output folder instead!

!!  Max will try to load the blankDLL.dll file and an error may pop up about it having no VST format,
    but it doesn't matter.  It's just a way of tricking the machine...


