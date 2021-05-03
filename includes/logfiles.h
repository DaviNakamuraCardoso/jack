
// Reads the register from the log file
// SONG* readlog(FILE* f);

// Saves the song queue to the log file
// void save_log(FILE* f, SONG* head);


void openlog(char* dir, SONG** head, SONG** played_head, int* size);

void close_queue(SONG* head, SONG* played);
