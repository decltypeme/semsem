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

#define _GNU_SOURCE
#define DEBUGGING_MODE
#include "extract.h"

#define INVALID_ARGS_MSG "Invalid command: Could not extract arguments\n"
#define UNABLE_GET_COMMAND_MSG "Unable to read command\n"


int main()
{
char **_args;
int should_run = 1;
char* line = NULL;
size_t len = 0;
int _argc = 0;
int i;
bool child_bg;
while(should_run)
{
	printf("osh>");
	if(getline(&line, &len, stdin) == -1)
	{
		printf(UNABLE_GET_COMMAND_MSG);
		goto END_OF_ITERATION;
	}
        #ifdef DEBUGGING_MODE
	printf("Command Entered: %s\n", line);//For debugging purposes
        #endif
	//Extract args
	_args = extract_args(line, len, &_argc, &child_bg);
	
        if(_args != NULL)
	{
		//Execute the command
            #ifdef DEBUGGING_MODE
		printf("Arguments: %d\n", _argc);
		for(i = 0; i < _argc; i++)
			{printf("%s\n", _args[i]);}
            #endif
	}
END_OF_ITERATION:
	//Flush the stdout
	fflush(stdout);
	//Free and nullify the string for storing the command
	free(line);
	line = NULL;
	//Empty the args array
	if(_args != NULL)
	{
		for(i = 0; i < _argc; i++)
	    		{free(_args[i]);
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
