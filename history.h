/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   history.h
 * Author: pilot
 *
 * Created on March 22, 2016, 1:42 AM
 */

#include "include.h"

#ifndef HISTORY_H
#define HISTORY_H




int get_history_index(void);
int set_history(char* hist[HISTORY_SIZE], int index, char* new_member);
char* get_history(char* hist[HISTORY_SIZE], int index);

#endif /* HISTORY_H */

