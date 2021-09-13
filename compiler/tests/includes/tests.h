/*
*   Header for the test program
*/

#include <tokenizer/test_tokens.h>
#include <tokenizer/test_precomp.h>
#include <tokenizer/test_reader.h>
#include <tokenizer/test_cleaner.h>
#include <tokenizer/test_parser.h>
#include <compengine/test_parser.h>
#include <compengine/test_compile.h>
#include <compengine/test_statements.h>
#include <compengine/test_expressions.h>
#include <compengine/test_structure.h>
#include <compengine/test_analyzer.h>
#include <table/test_table.h>
#include <table/test_parser.h>
#include <writer/test_loops.h>
#include <writer/test_tracker.h>
#include <writer/test_writer.h>
#include <writer/test_assignments.h>
#include <writer/test_functions.h>

unsigned int test_compilation(void);
unsigned int test_memory_leaks(void);

#define BASE_DIR ".."
