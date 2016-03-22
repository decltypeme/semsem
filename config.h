/*
 * semsem is a basic shell for Unix/Linux systems
 * Written by: Islam Faisal (decltypeme)
 * The American University in Cairo
 * For License, please see LICENSE 
 */

/*
 * File: config.h
 * Author: Islam Faisal
 * Configurations to be set before building
 */

#ifndef CONFIG_H
#define CONFIG_H


#define HISTORY_SIZE 10
#define SHELL_COOL_NAME "semsem"
//#define FAILED_HISTORY_IN_HISTORY
//#define HISTORY_IN_HISTORY
//#define DEBUGGING_MODE
#define INVALID_ARGS_MSG "Invalid command: Could not extract arguments\n"
#define UNABLE_GET_COMMAND_MSG "Unable to read command\n"
#define CHILD_FAILED_MSG "Command not found\n"
//#define MAX_ARGS_C 100            //Depreceated
//#define PRINT_CHILD_EXIT_CODE
//Child Process Exit Statuses
#define CHILD_FAILED -42

#endif /* CONFIG_H */

