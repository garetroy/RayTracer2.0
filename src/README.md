# C-Bed
Build system foundation for c/c++ oriented projects

Place source files in this directory. Note that your main source file's name should match the name of the project. 
This can be altered with ccmake (or the equivalent cmake flags/files, give the CMakeLists.txt a look for further explanation). 
You can also alter the preferred c++ file extension (defaults to cpp) as well as the build and include directory locations.

Also includes options for enabling/disabling debug flags and appending a debug suffix to the compiled debug executable.
