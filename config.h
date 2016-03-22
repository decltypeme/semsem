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


/*
 * CAUTION! CAUTION! CAUTION!
//Warning: Do not enable these two flags
//The use of them is depreceated
//#define DISPLAY_HISTORY_AS_IS
//#define FAILED_HISTORY_IN_HISTORY
 */
 

//#define HISTORY_IN_HISTORY
//#define DEBUGGING_MODE
#define INVALID_ARGS_MSG "Invalid command: Could not extract arguments\n"
#define UNABLE_GET_COMMAND_MSG "Unable to read command\n"
#define COMMAND_NOT_FOUND__MSG "Command not found\n"
//#define MAX_ARGS_C 100            //Depreceated
//#define PRINT_CHILD_EXIT_CODE
//Child Process Exit Statuses
#define CHILD_FAILED -42
#define ENABLE_PARENT_MESSAGE_ON_FAIULRE
#endif /* CONFIG_H */

