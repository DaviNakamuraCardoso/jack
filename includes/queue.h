// Header files for the queue module of the DC                                               Music Player (DMus)

// Song structure
typedef struct _song {
    char* path;
    unsigned int played:1;
    struct _song* next;
} SONG;

// Creates a new song
SONG* create_song(const char* path);

// Adds a song to the queue
void add_queue(SONG* hash[], char* path);

// Gets song out of the queue
SONG* pop_queue(SONG* hash[], unsigned short index);

// Releases the memory
void release_hash(SONG* hash[]);
