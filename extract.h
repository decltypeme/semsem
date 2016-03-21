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
#include "include.h"



int count_quotes(char* in_str);

char** extract_args(char* line, size_t len, int* argc, bool* child_bg);

char** appendArgument(char** args, char* arg, int* argc);


//End of header file
#endif
