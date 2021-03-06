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
2. Allowing processes to work concurrently with the shell.
3. Sending SIGINT to kill the process working in the foreground. [Under development see issue \#]

# Configuration
You may want to change configuration before building. All main configurations can be found in "config.h" Plase make sure to use either

***WARNING:*** **Deprecated arguments either do not have effect at all or changing them will cause problems or undefined behaviors. These are only left for debugging purposes**

Preprocessor | Effect
------------ | -------------
HISTORY_SIZE | The size of commands to be stored in the history.
SHELL_COOL_NAME | Our shell's cool name. Default is "semsem". Please if you change it, the octocat will not be happy.
INVALID_ARGS_MSG | A message to display when unable to extract arguments. Defaults to "Invalid command: Could not extract arguments\n"
UNABLE_GET_COMMAND_MSG | Message to display if unable to read command from stdin. Default: "Unable to read command\n"
COMMAND_NOT_FOUND__MSG | A message to display if the command was not found i.e. if (errno == ENOENT). Default: "Command not found\n". **If the process creation failed for other reasons. errno is resolved and the appropriate message is displayed to the user**
PRINT_CHILD_EXIT_CODE | Disabled by default. Upon child process termination, the exit code is printed with a message.
DEBUGGING_MODE | Prints helpful messages specially on parsing. Disabled by default.
DISPLAY_HISTORY_AS_IS |**DEPRECATED**: Enabling will cause weird problems. Disabling it makes semsem behave like bash.
FAILED_HISTORY_IN_HISTORY |**DEPRECATED**: Enabling will cause weird problems. Disabling it makes semsem behave like bash.
MAX_ARGS_C | **DEPRECATED**: The maximum number of arguments. Currently, we use realloc.
# How to install on Linux

## Using gcc
Type this into the terminal when being in the main semsem directory.
```
mkdir bin && gcc *.c -o bin/semsem
```

## Using the Makefile generated by NetBeans
**The following build via the provided Makefile was generated by NetBeans. If you do not have NetBeans and had problems building, please run follow the instructions above. It needs gcc only [at least that is what I know :-) ]**

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
The binary distribution can be called as
```
./dist/Debug/GNU-Linux/semsem
```
or simply run build.sh but make sure you have execution permissions.
# Syntactic Rules
1. Anything starting with "!" is a history command
2. !N and ! N are treated the same.
3. ""! 2foo" would work as ""! 2"
4. The history command by default is not stored in history, if you want build with HISTORY_IN_HISTORY
5. Calling ! N will place in history the corresponding command and not the "! N" command. Example 123 ls is in the history. Doing ! 123 will store ls in the history.
6. Unlike bash, we do ignore anything after "! N" except for "&". Multiple occurrences of "&" are treated the same. Issue \#5 is meant to make semsem like bash in this feature.
7. Unsuccessful calls for history are not placed in history
8. Calling "!5 &" will make the most recent command same as 5. However, at this point of call to the command, it will execute in the background.

# Process Creation Rule
1. When a process is created in the background, its input/output and error streams are **NOT** redircted by default. Things might get into semsem if the process writes to stdout. That is how bash would do it and how we would do it. Input/Output redirection will be included in a future version.
2. Passing the Ctrl + C will kill the child process in the foreground if any
3. When creating a process, we distinguish between a "file not found error" and an error caused returned by execvp. Proper messages are printed to the user.
