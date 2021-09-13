/**
*
*       Headers for the source structure
*
*
*/
#ifndef TRACKERH
#define TRACKERH

typedef struct _tracker {
    unsigned long counter;
} TRACKER;

TRACKER* new_tracker(void);
void release_tracker(TRACKER* t); 

#endif
