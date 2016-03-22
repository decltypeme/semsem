/*
 * semsem is a basic shell for Unix/Linux systems
 * Written by: Islam Faisal (decltypeme)
 * The American University in Cairo
 * For License, please see LICENSE 
 */

/*
 * File: history.h
 * Author: Islam Faisal
 * For handling the history feature
 */

#include "include.h"

#ifndef HISTORY_H
#define HISTORY_H



int get_history_index(bool increment);
int set_history(char* hist[HISTORY_SIZE], int index, char* new_member);
char* get_history(char* hist[HISTORY_SIZE], int index);
void print_all_history(char* hist[HISTORY_SIZE]);

#endif /* HISTORY_H */

