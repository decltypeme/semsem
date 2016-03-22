/*
 * semsem is a basic shell for Unix/Linux systems
 * Written by: Islam Faisal (decltypeme)
 * The American University in Cairo
 * For License, please see LICENSE 
 */

/*
 * File: extract.h
 * Author: Islam Faisal
 * Arguments extraction and command parsing
 */

#ifndef EXTRACT_H
#define EXTRACT_H
#include "include.h"


int count_quotes(char* in_str);

char** extract_args(char* line, size_t len, int* argc, bool* child_bg);

char** appendArgument(char** args, char* arg, int* argc);


//End of header file
#endif
