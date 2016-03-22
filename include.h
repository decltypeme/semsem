/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   include.h
 * Author: pilot
 *
 * Created on March 22, 2016, 1:56 AM
 */

#ifndef INCLUDE_H
#define INCLUDE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "config.h"
#define INVALID_ARGS_MSG "Invalid command: Could not extract arguments\n"

#define MAX_ARGS_C 100
//Regex before escaping (?:(?:")(\\"|[^"]*)(?:"))|([^\s]+)
//(?:(?:\")(\\\\\"|[^\"]*)(?:\"))
#define REGEX_ARGS_RULE "([\\S]+)+"


#define _GNU_SOURCE



#define UNABLE_GET_COMMAND_MSG "Unable to read command\n"

#endif /* INCLUDE_H */

