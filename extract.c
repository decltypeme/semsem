/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "extract.h"

char** appendArgument(char** args, char* arg, int* argc) {
    /*
     * Depreceated static code
    if((*argc) >= MAX_ARGS_C)
    {
        printf("Warning: Maximum number of arguments exceeded. Some arguments have been truncated\n");
        return;
    }
    //Need to do dynamic re-allocation
     * 
     */
    size_t target_length = strlen(arg);
    //Adapted from the code sent in the lecture

    if ((args = (char **) realloc(args, (*argc + 2) * sizeof (char *))) == NULL) {
        fprintf(stderr, "error allocating memory in realloc\n");
        exit(1);
    }
    args[*argc] = (char*) calloc(target_length, sizeof (char));
    strcpy(args[*argc], arg);
    (*argc)++;
    args[*argc] = NULL;
    return args;
}

/*
 *Quotes count function
 * Syntactic Checker for each opening quote is matched by a closing quote
 * We pursue the choice of getting the command in one line
 * Escaped quotes are not counted
 * After parsing the escape character is removed and the quote is left
 */
int count_quotes(char* in_str) {
    int count = 0, i;
    for (i = 0; in_str[i] != '\0'; i++)
        if (in_str[i] == '"')
            if (i > 0) //Just to avoid invalid indexation
            {
                if (in_str[i - 1] != '\\')
                    count++;
            } else {
                count++;
            }
    return count;
}

/**
 * 
 * @param line
 * @param len
 * @param args
 * @param argc
 * @param child_wait
 * @return 
 * Assumes & must be at the end of 
 */
char** extract_args(char* _line, size_t len, int* argc, bool* child_bg) {
    //if(count_quotes(line)%2 != 0)
    //	printf("Invalid command: An open quote was not matched by a closed quote\n");
    char* line;              //Deep copy override strtok will destroy line, so we do this
    line = (char*) calloc(strlen(_line), sizeof(char));
    strcpy(line, _line);
    char** args = NULL;
    char* single_arg;
    (*argc) = 0;
    //Determine whether you should wait
    (*child_bg) = false;
    int it = strlen(line) - 1;
    //Fancy syntax :D
    //It keeps iterating as long as we have a space or we encounter an &
    //Once we encounter an &, we change the flag, iteration will stop next time
    for (; it >= 0 && !(*child_bg) && (isspace(line[it]) || ((*child_bg) = ((line[it]) == '&' && (it == 0 || isspace(line[it - 1]))))); it--);
    //If we are going to launch in background, we remove the &
    if (*child_bg) {
        it++;
        line[it] = '\0';
    }
    //Now, we start extracting parameters; Some code is adapted from the code sent in the lecture.
    if ((single_arg = strtok(line, " \t\n")) == NULL) {
        /* Check for empty line */
        free(line);
        return args; /* NULL */
    }
    args = appendArgument(args, single_arg, argc);
    while ((single_arg = strtok(NULL, " \t\n")) != NULL) {
        args = appendArgument(args, single_arg, argc);
    }
    free(line);
    return args;

}


/*
A failed regular expressions attempt
bool extract_args(char* line, size_t len, char*** args, int* argc, bool* child_wait)
{
        //Determine whether you should wait
        int i;
        regmatch_t pmatch[MAX_ARGS_C];
        regex_t regx;
        if(regcomp(&regx, REGEX_ARGS_RULE, REG_EXTENDED ) != 0){
                printf("Pattern failed to compile\n");
                return false;
        }
        if(regexec(&regx, line, MAX_ARGS_C, pmatch, REG_EXTENDED)==REG_NOMATCH){
                printf("Could not extract\n");
                return false;
        }
        //Get the arguments count
        for(i = 0 ; i < MAX_ARGS_C && pmatch[i].rm_so!=-1 ; i++){
                (*argc)++;
        }
        //Allocate memory for the arugments
        (*args) = (char**) calloc (*argc,sizeof(char*));
        for(i = 0; i < (*argc); i++)
        {
                size_t arg_length = pmatch[i].rm_eo - pmatch[i].rm_so;
                arg_length++;
                (*args)[i] = (char*) calloc(arg_length + 1, sizeof(char));
                strncpy((*args)[i], &line[pmatch[i].rm_so], arg_length);
                (*args)[i][arg_length] = '\0';
                printf("%s\n", &(*args)[i][0]);
        }
        return true;
}*/