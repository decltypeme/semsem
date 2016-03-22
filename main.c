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

int main(int main_argc, char** main_argv) {
    //Some declarations
    char* shell_hist[HISTORY_SIZE];
    memset(shell_hist, 0 , sizeof(shell_hist));
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
        
        //Command entered
#ifdef DEBUGGING_MODE
        printf("Command Entered: %s\n", line); //For debugging purposes
#endif
AFTER_INPUT:
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
            if (strcmp(_args[0], "exit") == 0) {
                should_run = false;
                goto END_OF_ITERATION;
            }
            else if(strcmp(_args[0], "history") == 0)
            {
                print_all_history(shell_hist);
                goto END_OF_ITERATION;
            }
            //Now, we check if it is a history command
            else if(_args[0] == "!")
            {
                char* command;
                if(_argc > 1)
                {
                    int hist_index;
                    if(strcmp(_args[1], "!") == 0)
                        hist_index = get_history_index(false);
                    else
                    {
                        hist_index = atoi(_args[1]);
                        if(hist_index == 0)
                            printf("No such command in history, Bonus: Enter a valid integer after !\n");
                    }
                    command = get_history(shell_hist, hist_index);
                    if(command == NULL)
                    {
                        printf("No such command in history\n");
                    }
                    else
                    {
                        free(line);
                        //Deep copy because of the routine freeing at the end
                        line = (char*) calloc(strlen(command), sizeof(char));
                        strcpy(line, command);
                        printf("%s\n", line);
                        goto AFTER_INPUT;
                    }
                    
                }
                else
                {
                    fprintf(stderr, "You monster, you need to tell us which command to retrieve from the history: Syntax ! ! or ! N\n");
                }
            }


        }
END_OF_ITERATION:
        //Flush the stdout
        fflush(stdout);
        //Free and nullify the string for storing the command
        //Add to history
        set_history(shell_hist, get_history_index(true) % HISTORY_SIZE, line);
        //Free some memory, communists would like it :D
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
