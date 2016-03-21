/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "extract.h"


int count_quotes(char* in_str)
{
	int count = 0;
	for(int i = 0; in_str[i] != '\0'; i++)
		if(in_str[i] == '"')
			if(i > 0)
			{	if(in_str[i-1] != '\\')
					count++;
			}
			else
			{
				count++;
			}
	return count;
}

bool extract_args(char* line, size_t len, char** args, int* argc, bool* child_wait)
{
	int it = strlen(line) - 1;
	for(; it >

}


/*
A failed regular expressions attempt
bool extract_args(char* line, size_t len, char** args, int* argc, bool* child_wait)
{
	//Determine whether you should wait
	regmatch_t pmatch[MAX_ARGS_C];
	regex_t regx;
	if(regcomp(&regx, REGEX_ARGS_RULE, REG_EXTENDED ) != 0){
		printf("Pattern failed to compile\n");
		return false;
	}
    	if(regexec(&regx, line, MAX_ARGS_C, pmatch,REG_EXTENDED)==REG_NOMATCH){
		printf("Could not extract\n");
        	return false;
   	}
	//Get the arguments count
    	for(int i = 0 ; i < MAX_ARGS_C && pmatch[i].rm_so!=-1 ; i++){
		(*argc)++;
    	}
	//Allocate memory for the arugments
	args = (char**) calloc (*argc,sizeof(char*));
	for(int i = 0; i < (*argc); i++)
	{
		size_t arg_length = 1 + pmatch[i].rm_eo - pmatch[i].rm_so;
		args[i] = (char*) calloc(arg_length + 1, sizeof(char));
		strncpy(args[i], &line[pmatch[i].rm_so], arg_length);
		args[i][arg_length] = '\0';
		printf("%s\n", &args[i][0]);
	}
	return true;
}*/