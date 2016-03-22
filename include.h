/*
 * semsem is a basic shell for Unix/Linux systems
 * Written by: Islam Faisal (decltypeme)
 * The American University in Cairo
 * For License, please see LICENSE 
 */

/*
 * File: include.h
 * Author: Islam Faisal
 * A list of files to be included
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

