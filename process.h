/*
 * semsem is a basic shell for Unix/Linux systems
 * Written by: Islam Faisal (decltypeme)
 * The American University in Cairo
 * For License, please see LICENSE 
 */

/*
 * File: process.h
 * Author: Islam Faisal
 * Utility functions to handle child jobs submitted to the shell
 */

#ifndef PROCESS_H
#define PROCESS_H
#include "include.h"
void SIG_INT_HANDLER(int sig);
void SIG_TSTP_HANDLER(int sig);
void flush_all_buffers(void);
void execute(char** _args, int _argc, bool _bg);

#endif /* PROCESS_H */

