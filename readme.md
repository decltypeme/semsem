#Dependencies
gnome-terminal

# How to install

#

# Notes
1. Adding parameters more than MAX_ARGS_C causes undefined behaviour.
2. Spaces are forced after "!" otherwise the compiler would treat them as one argument
3. Same for the history command
4. ! 2asv would work as ! 2
5. Assumption: history is NOT recorded in history, if you want build with HISTORY_IN_HISTORY
6. Calling ! 1 will place in history the corresponding 
