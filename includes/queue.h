// Header files for the queue module of the DC                                               Music Player (DMus)

// Song structure
typedef struct _song {
    const char* path;
    unsigned int played:1;
    struct _song* next;

} SONG;

SONG* new_song(const char* path, unsigned int played); 
