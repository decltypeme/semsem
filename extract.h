/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   extract.h
 * Author: pilot
 *
 * Created on March 21, 2016, 10:55 PM
 */

#ifndef EXTRACT_H
#define EXTRACT_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_ARGS_C 100
//Regex before escaping (?:(?:")(\\"|[^"]*)(?:"))|([^\s]+)
//(?:(?:\")(\\\\\"|[^\"]*)(?:\"))|
#define REGEX_ARGS_RULE "(.+)$"

int count_quotes(char* in_str);

bool extract_args(char* line, size_t len, char** args, int* argc, bool* child_wait);


//End of header file
#endif
