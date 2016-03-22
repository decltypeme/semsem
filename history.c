/*
 * semsem is a basic shell for Unix/Linux systems
 * Written by: Islam Faisal (decltypeme)
 * The American University in Cairo
 * For License, please see LICENSE 
 */

/*
 * File: history.c
 * Author: Islam Faisal
 * For handling the history feature
 */

#include "history.h"

//Must be zero indexed
bool check_in_history(int index)
{
    //Old checking, buggy:: get_history_index(false)/HISTORY_SIZE == index / HISTORY_SIZE;
    //New method: we get the start and end, zero indexed and we check if in range.
    int start = 0;
    int end = get_history_index(false);
    if(end == -1)
        return false;                       //No commands are there aslan :D
    if(end >= HISTORY_SIZE)
        start = end - HISTORY_SIZE + 1;
    return (index >= start && index <= end);
}

int get_history_index(bool increment)
{
    static int our_secret_index = -1;
    if(increment)
        our_secret_index = (our_secret_index + 1);
    return our_secret_index; //% HISTORY_SIZE;
}

int set_history(char* hist[HISTORY_SIZE], int index, char* new_member)
{
    if(index >= HISTORY_SIZE || index < 0)
        return -1;
    if(hist[index] != 0)
        free (hist[index]);
    size_t target_length = strlen(new_member);
    hist[index] = (char*) calloc(target_length, sizeof(char));
    strcpy(hist[index], new_member);
    return 1;
}

char* get_history(char* hist[HISTORY_SIZE], int index)
{
    if(get_history_index(false) == -1)
        return NULL;                        //No history so far
    if(check_in_history(index))
        return hist[index % HISTORY_SIZE];
    else
        return NULL;
}

void print_all_history(char* hist[HISTORY_SIZE])
{
    int start = 0;
    int end = get_history_index(false);
    if(end == -1)
        printf("No commands in history\n");
    if(end >= HISTORY_SIZE)
        start = end - HISTORY_SIZE + 1;
    while(start <= end)
    {
        char* command = hist[start % HISTORY_SIZE];
        if(command == NULL)
            fprintf(stderr, "Internal error occurred while retrieving from history\n");
        printf("%d\t%s", start + 1, command);
        start++;
    }
    return;
}