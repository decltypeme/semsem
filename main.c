/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: pilot
 *
 * Created on March 21, 2016, 10:47 PM
 */


#include "semsem.h"

char* shell_hist[HISTORY_SIZE];

#define UNABLE_GET_COMMAND_MSG "Unable to read command\n"

int main(int main_argc, char** main_argv) {
    //Some declarations
    char* line = NULL;
    char **_args = NULL;
    bool should_run = true, child_bg = false;
    size_t len = 0;
    int _argc = 0, i;

    while (should_run) {
        printf("%s>", SHELL_COOL_NAME);
        if (getline(&line, &len, stdin) == -1) {
            fprintf(stderr, UNABLE_GET_COMMAND_MSG);
            goto END_OF_ITERATION;
        }
#ifdef DEBUGGING_MODE
        printf("Command Entered: %s\n", line); //For debugging purposes
#endif
        //Extract args
        _args = extract_args(line, len, &_argc, &child_bg);
        if (_args != NULL) {
#ifdef DEBUGGING_MODE
            printf("Arguments: %d\n", _argc);
            for (i = 0; i < _argc; i++) {
                printf("%s\n", _args[i]);
            }
#endif
            //Execute the command
            //Exit command; Any additional arguments are ignored
            if (strcmp(_args[0], "exit")) {
                should_run = false;
                goto END_OF_ITERATION;
            }
            //Now, we check if it is a history command
            if(_args[0] == "!")
            {
                if(_argc > 1)
                {
                    
                }
            }


        }
END_OF_ITERATION:
        //Flush the stdout
        fflush(stdout);
        //Free and nullify the string for storing the command
        free(line);
        line = NULL;
        //Empty the args array
        if (_args != NULL) {
            for (i = 0; i < _argc; i++) {
                free(_args[i]);
                _args[i] = NULL;
            }
            free(_args);
            _args = NULL;
        }
        //Set the args count to zero
        _argc = 0;
    }


    return 0;
}
