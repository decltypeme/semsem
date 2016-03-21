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
#include "extract.h"

#define INVALID_ARGS_MSG "Invalid command: Could not extract arguments\n"
#define UNABLE_GET_COMMAND_MSG "Unable to read command\n"


int main(int argc, char** argv)
{
char **args;
int should_run = 1;
char* line = NULL;
size_t len = 0;
int argc = 0;
bool child_wait;
while(should_run)
{
	printf("osh>");
	if(getline(&line, &len, stdin) == -1)
	{
		printf(UNABLE_GET_COMMAND_MSG);
		goto END_OF_ITERATION;
	}
	printf("Command Entered: %s\n", line);
	//Extract args
	if(count_quotes(line)%2 != 0)
		printf("Invalid command: An open quote was not matched by a closed quote\n");
	bool healthy_args = true;//extract_args(line, len, args, &argc, &child_wait);
	if(healthy_args)
	{
		//Execute the command
		printf("Arguments: %d\n", argc);
		for(int i = 0; i < argc; i++)
			{printf("%s", &args[i][0]);}
	}
	else
	{
		//Print error message to the user
		printf(INVALID_ARGS_MSG);
	}
END_OF_ITERATION:
	//Flush the stdout
	fflush(stdout);
	//Free and nullify the string for storing the command
	free(line);
	line = NULL;
	//Empty the args array
	/*if(healthy_args)
	{
		for(int i = 0; i < argc; i++)
	    		{free(args[i]);
			args[i] = NULL;
			}
		free(args);
		args = NULL;
	}*/	
	//Set the args count to zero
	argc = 0;
}


return 0;
}
