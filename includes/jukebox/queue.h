// Header files for the queue module of the DC                                               Music Player (DMus)

// Song structure
typedef struct _song {
    char* path;
    unsigned int played:1;
    struct _song* next;

} SONG;

SONG* new_song(const char* path, unsigned int played);
SONG** new_queue(const char* path);
void release_song(SONG** s);
void release_queue(SONG** q);
