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
Preprocessor | Effect
------------ | -------------
DISPLAY_HISTORY_AS_IS | DEPRECATED: Enabling will cause weird problems. Disabling it makes semsem behave like bash.
FAILED_HISTORY_IN_HISTORY | DEPRECATED: Enabling will cause weird problems. Disabling it makes semsem behave like bash.

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
1. Anything starting with "!" is a history command
2. !N and ! N are treated the same.
3. ""! 2foo" would work as ""! 2"
4. The history command by default is not stored in history, if you want build with HISTORY_IN_HISTORY
5. Calling ! N will place in history the corresponding command and not the "! N" command. Example 123 ls is in the history. Doing ! 123 will store ls in the history.
6. Unlike bash, we do ignore anything after "! N" except for "&". Multiple occurrences of "&" are treated the same. Issue \#5 is meant to make semsem like bash in this feature.
7. Unsuccessful calls for history are not placed in history
8. Calling "!5 &"" will make the most recent command same as 5. However, at this point of call to the command, it will execute in the background.

# Process Creation Rule
1. When a process is created in the background, its input/output and error streams are not redircted. That is how bash would do it and how we would do it. Input/Output redirection will be included in a future version.
2. Passing the Ctrl + C will kill the child process in the foreground if any
3. Passing Ctrl + D will cause the shell to exit
