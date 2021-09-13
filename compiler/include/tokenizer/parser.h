

void write_xml(char* tagname, char* content, FILE* xml);

TOKEN_TYPE get_type(SYMBOL* tables_type, char* token);

SYMBOL* new_types_table(void);

char* get_tagname(TOKEN_TYPE type);

char* get_xml(char* source);

char* tokenize(char* filename);
