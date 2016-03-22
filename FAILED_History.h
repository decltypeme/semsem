/*
 * semsem is a basic shell for Unix/Linux systems
 * Written by: Islam Faisal (decltypeme)
 * The American University in Cairo
 * For License, please see LICENSE 
 */

/*
 * File: FAILED_History.h
 * Author: Islam Faisal
 * A preprocessor directive to be included whenever needed
 */

#ifdef FAILED_HISTORY_IN_HISTORY
                        goto END_OF_ITERATION;
#endif
#ifndef FAILED_HISTORY_IN_HISTORY
                        goto AFTER_SAVING_HISTORY;
#endif