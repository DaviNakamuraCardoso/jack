
// Program loop
void loop(char* dir);

// Catches program signals
int catch_signal(int sig, void (*handler) (int));

void kill_handler(int sig); 
