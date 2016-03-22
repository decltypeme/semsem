/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "history.h"


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
    if(hist[index] != NULL)
        free (hist[index]);           //No problem if null :D check free's documentation
    size_t target_length = strlen(new_member);
    hist[index] = (char*) calloc(target_length, sizeof(char));
    strcpy(hist[index], new_member);
    return 1;
}

char* get_history(char* hist[HISTORY_SIZE], int index)
{
    if(get_history_index(false) == -1)
        return NULL;                        //No history so far
    if(get_history_index(false) == index / HISTORY_SIZE)
    return hist[index % HISTORY_SIZE];
}

void print_all_history(char* hist[HISTORY_SIZE])
{
    int end = get_history_index(false);
    if(end == -1)
        printf("No commands in history\n");
    int start = end - HISTORY_SIZE + 1;
    while(start <= end)
    {
        char* command = get_history(hist, start);
        if(command == NULL)
            fprintf(stderr, "Internal error occurred while retrieving from history\n");
        printf("%d\t%s", start, command);
        start++;
    }
    return;
}