/*
 * semsem is a basic shell for Unix/Linux systems
 * Written by: Islam Faisal (decltypeme)
 * The American University in Cairo
 * For License, please see LICENSE 
 */

/*
 * File: process.c
 * Author: Islam Faisal
 * Utility functions to handle child jobs submitted to the shell
 */
#include "process.h"

void flush_all_buffers(void)
{
    fflush(stdout);
    fflush(stderr);
    fflush(stdin);
}

void execute(char** _args, int _argc, bool _bg)
{
    flush_all_buffers();
    pid_t pid = fork();
    //Failed to create process
    if(pid == -1)
    {
        fprintf(stderr, "Failed to create a child process\n");
        return;
    }
    //We are in the child's code
    else if(pid == 0)
    {
        //If the process is set to work in the background, we need to strip him from the pipes.
        if (execvp(_args[0], _args)==-1)
        {
            printf("%s", CHILD_FAILED_MSG);
            exit(CHILD_FAILED);
        }
    }
    //We are in the parent's code
    else
    {
        //You know parents need to have some control over their children
        //If the process is not set to work in the background, we must wait.
        if(!_bg)
        {
            int exit_status;
            //Wait till child executes either normally or abnormally
            waitpid(pid, &exit_status, 0);
            flush_all_buffers();
#ifdef PRINT_CHILD_EXIT_CODE
            printf("Child process exited with %d\n", exit_status);
#endif
        }
    }
}