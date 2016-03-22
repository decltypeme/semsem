# semsem
semsem is a basic shell for Unix/Linux systems
# Repository Structure
```
semsem
│   README.md
│   LICENSE
|   Makefile
|   .gitignore
|   .dep.inc
  Header Files
│   FAILED_History.h          A preprocessor directive
│   config.h
│   extract.h
│   history.h
│   include.h
│   process.h
│   semsem.h
  C Source Files
│   extract.c
│   history.c
│   main.c
│   process.c
└───nbproject (NetBeans project files)

```

# Features
1. History of previous commands
2. Allowing processes to work in the background.
3. Sending SIGINT to kill the process working in the foreground.

# Configuration
You may want to change configuration before building. All main configurations can be found in "config.h"

# How to install on Linux
1. Download the code by downloading the zip file from this page or if you want to download the whole repository, you may do
```
git clone https://github.com/decltypeme/semsem.git
```
2. Make sure you are in the main directory of the repository.
3. Make sure you have CMake
4. Type
```
make
```
5. The binary distribution shall be in
```
./dist/Debug/GNU-Linux/semsem
```

# Syntactic Rules
1. Adding parameters more than MAX_ARGS_C causes undefined behaviour.
2. Spaces are forced after "!" otherwise the compiler would treat them as one argument
3. Same for the history command
4. ! 2asv would work as ! 2
5. Assumption: history is NOT recorded in history, if you want build with HISTORY_IN_HISTORY
6. Calling ! 1 will place in history the corresponding
7. Unsucessful calls for history are not placed in history
8. Anything starting with "!" is a history command
9. SIGINT are handled to terminate the current process in the foreground
10. Calling "!5 &"" will make the most recent command same as 5. However, at this point of call to the command, it will execute in the background.

# Process Creation Rule
1. A process that is not set to work in the background and returns the CHILD_FAILED status defined in config.h, will be treated as a failed process and this will result in an error message printed on the screen. Child execution is not affected however.
