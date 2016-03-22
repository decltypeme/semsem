#ifdef FAILED_HISTORY_IN_HISTORY
                        goto END_OF_ITERATION;
#endif
#ifndef FAILED_HISTORY_IN_HISTORY
                        goto AFTER_SAVING_HISTORY;
#endif