// Header files for the queue module of the DC Music Player (DMus)

// Song structure
typedef struct _song {
    char* path;
    struct _song* next;
    unsigned int called:1;

} SONG;

// Creates a new song
SONG* create(const char* path);

// Adds a song to the queue
void add_queue(SONG** tail, char* name);

// Gets song out of the queue
SONG* call_queue(SONG* head, unsigned int* q_size);

// Releases the memory
void release(SONG* head);
