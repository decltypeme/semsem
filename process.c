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

int current_child_executing_pid = -1;

void SIG_INT_HANDLER(int sig) {
    if (current_child_executing_pid != -1) {
        kill(current_child_executing_pid, SIGKILL);
    }
    return;
}

void SIG_TSTP_HANDLER(int sig) {
    if (current_child_executing_pid != -1) {
        kill(current_child_executing_pid, SIGSTOP);
    }
    return;
}

void flush_all_buffers(void) {
    fflush(stdout);
    fflush(stderr);
    fflush(stdin);
}

void execute(char** _args, int _argc, bool _bg) {
    flush_all_buffers();
    pid_t pid = fork();
    //Failed to create process
    if (pid == -1) {
        fprintf(stderr, "Failed to create a child process\n");
        return;
    }//We are in the child's code
    else if (pid == 0) {
        if (execvp(_args[0], _args) == -1) {
            if (errno == ENOENT)
                printf("%s", COMMAND_NOT_FOUND__MSG);
            else {
                printf("%s\n", strerror(errno));
            }
            exit(CHILD_FAILED);
        }
    }//We are in the parent's code
    else {
        //You know parents need to have some control over their children
        //If the process is not set to work in the background, we must wait.
        if (!_bg) {
            current_child_executing_pid = pid;
            int exit_status;
            //Wait till child executes either normally or abnormally
            waitpid(pid, &exit_status, 0);
            flush_all_buffers();
            current_child_executing_pid = -1;
#ifdef ENABLE_PARENT_MESSAGE_ON_FAIULRE
            if (exit_status == CHILD_FAILED)
                printf("The child process was not created successfully.\n");
#endif
#ifdef PRINT_CHILD_EXIT_CODE
            printf("Child process exited with %d\n", exit_status);
#endif
        }
    }
}