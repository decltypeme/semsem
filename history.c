/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "history.h"

int get_history_index(void)
{
    static int our_secret_index = -1;
    our_secret_index = (our_secret_index + 1) % HISTORY_SIZE;
    return our_secret_index;
}

int set_history(char* hist[HISTORY_SIZE], int index, char* new_member)
{
    if(index >= HISTORY_SIZE || index < 0)
        return -1;
    free hist[index];           //No problem if null :D check free's documentation
    size_t target_length = strlen(new_member);
    hist[index] = (char*) calloc(target_length, sizeof(char));
    strcpy(hist[index], new_member);
    return 1;
}

char* get_history(char* hist[HISTORY_SIZE], int index)
{
    return hist[index];
}