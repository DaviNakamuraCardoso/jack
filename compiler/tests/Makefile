# Makefile for the test suite of the Davi Compiler Collection


# (S)ource, (L)ibraries, (O)bjects, (H)eaders
S = ./src/
L = ./lib/
O = ./obj/
H = ./includes/

# (T)okenizer, (C)ompilation engine, (U)tils, ta(B)le, (W)riter
T = tokenizer/
C = compengine/
U = utils/
B = table/
W = writer/

# (TH) Tested Header, (TS) Tested Source
TH = ./../include/
TS = ./../src/

CH = ./../include/
CS = ./../src/

# Test the creation of tokens
$(O)$(T)test_tokens.o: $(S)$(T)test_tokens.c
	gcc -I$(TH) -c $(S)$(T)test_tokens.c -o $(O)$(T)test_tokens.o

# Get the tokenizer module
$(O)$(T)tokens_test.o: $(TS)$(T)tokens.c
	gcc -I$(TH) -c $(TS)$(T)tokens.c -o $(O)$(T)tokens_test.o

# Test the precomp
$(O)$(T)test_precomp.o: $(S)$(T)test_precomp.c
	gcc -I$(TH) -c $(S)$(T)test_precomp.c -o $(O)$(T)test_precomp.o

# Get the precomp module
$(O)$(T)precomp_test.o: $(TS)$(T)precomp.c
	gcc -I$(TH) -c $(TS)$(T)precomp.c -o $(O)$(T)precomp_test.o

# Test the precomp
$(O)$(T)test_cleaner.o: $(S)$(T)test_cleaner.c
	gcc -I$(TH) -c $(S)$(T)test_cleaner.c -o $(O)$(T)test_cleaner.o

# Test the reader
$(O)$(T)test_reader.o: $(S)$(T)test_reader.c
	gcc -I$(TH) -c $(S)$(T)test_reader.c -o $(O)$(T)test_reader.o

# Get the reader module
$(O)$(T)test_module_reader.o: $(TS)$(T)reader.c
	gcc -I$(TH) -c $(TS)$(T)reader.c -o $(O)$(T)test_module_reader.o

# Get the precomp module
$(O)$(T)cleaner_test.o: $(TS)$(T)cleaner.c
	gcc -I$(TH) -c $(TS)$(T)cleaner.c -o $(O)$(T)cleaner_test.o

# Test the parser
$(O)$(T)test_parser.o: $(S)$(T)test_parser.c
	gcc -I$(TH) -c $(S)$(T)test_parser.c -o $(O)$(T)test_parser.o

# Get the parser module
$(O)$(T)test_module_parser.o: $(TS)$(T)parser.c
	gcc -I$(TH) -c $(TS)$(T)parser.c -o $(O)$(T)test_module_parser.o

# Test the parser
$(O)$(C)test_parser.o: $(S)$(C)test_parser.c
	gcc -I$(TH) -c $(S)$(C)test_parser.c -o $(O)$(C)test_parser.o

# Get the parser module
$(O)$(C)test_module_parser.o: $(CS)$(C)parser.c
	gcc -I$(TH) -c $(CS)$(C)parser.c -o $(O)$(C)test_module_parser.o

# Test the statements
$(O)$(C)test_statements.o: $(S)$(C)test_statements.c
	gcc -I$(CH) -c $(S)$(C)test_statements.c -o $(O)$(C)test_statements.o

# Get the statements module
$(O)$(C)test_module_statements.o: $(CS)$(C)statements.c
	gcc -I$(CH) -c $(CS)$(C)statements.c -o $(O)$(C)test_module_statements.o

# Test the compile
$(O)$(C)test_compile.o: $(S)$(C)test_compile.c
	gcc -I$(CH) -c $(S)$(C)test_compile.c -o $(O)$(C)test_compile.o

# Get the compile module
$(O)$(C)test_module_compile.o: $(CS)$(C)compile.c
	gcc -I$(CH) -c $(CS)$(C)compile.c -o $(O)$(C)test_module_compile.o


# Test the expressions
$(O)$(C)test_expressions.o: $(S)$(C)test_expressions.c
	gcc -I$(CH) -c $(S)$(C)test_expressions.c -o $(O)$(C)test_expressions.o

# Get the expressions module
$(O)$(C)test_module_expressions.o: $(CS)$(C)expressions.c
	gcc -I$(CH) -c $(CS)$(C)expressions.c -o $(O)$(C)test_module_expressions.o


# Test the structure
$(O)$(C)test_structure.o: $(S)$(C)test_structure.c
	gcc -I$(CH) -c $(S)$(C)test_structure.c -o $(O)$(C)test_structure.o

# Get the structure module
$(O)$(C)test_module_structure.o: $(CS)$(C)structure.c
	gcc -I$(CH) -c $(CS)$(C)structure.c -o $(O)$(C)test_module_structure.o

# Test the analyzer
$(O)$(C)test_analyzer.o: $(S)$(C)test_analyzer.c
	gcc -I$(CH) -c $(S)$(C)test_analyzer.c -o $(O)$(C)test_analyzer.o

# Get the analyzer module
$(O)$(C)test_module_analyzer.o: $(CS)$(C)analyzer.c
	gcc -I$(CH) -c $(CS)$(C)analyzer.c -o $(O)$(C)test_module_analyzer.o
# Test the table
$(O)$(B)test_table.o: $(S)$(B)test_table.c
	gcc -I$(TH) -c $(S)$(B)test_table.c -o $(O)$(B)test_table.o

# Get the table module
$(O)$(B)test_module_table.o: $(TS)$(B)table.c
	gcc -I$(TH) -c $(TS)$(B)table.c -o $(O)$(B)test_module_table.o

# Test the parser
$(O)$(B)test_parser.o: $(S)$(B)test_parser.c
	gcc -I$(TH) -c $(S)$(B)test_parser.c -o $(O)$(B)test_parser.o

# Get the parser module
$(O)$(B)test_module_parser.o: $(TS)$(B)parser.c
	gcc -I$(TH) -c $(TS)$(B)parser.c -o $(O)$(B)test_module_parser.o

$(O)$(U)comptests.o: $(CS)$(U)comptests.c
	gcc -I$(CH) -c $(CS)$(U)comptests.c -o $(O)$(U)comptests.o

# Test the loops
$(O)$(W)test_loops.o: $(S)$(W)test_loops.c
	gcc -I$(TH) -c $(S)$(W)test_loops.c -o $(O)$(W)test_loops.o

# Get the loops module
$(O)$(W)test_module_loops.o: $(TS)$(W)loops.c
	gcc -I$(TH) -c $(TS)$(W)loops.c -o $(O)$(W)test_module_loops.o

# Test the tracker
$(O)$(W)test_tracker.o: $(S)$(W)test_tracker.c
	gcc -I$(TH) -c $(S)$(W)test_tracker.c -o $(O)$(W)test_tracker.o

# Get the tracker module
$(O)$(W)test_module_tracker.o: $(TS)$(W)tracker.c
	gcc -I$(TH) -c $(TS)$(W)tracker.c -o $(O)$(W)test_module_tracker.o

# Test the writer
$(O)$(W)test_writer.o: $(S)$(W)test_writer.c
	gcc -I$(TH) -c $(S)$(W)test_writer.c -o $(O)$(W)test_writer.o

# Get the writer module
$(O)$(W)test_module_writer.o: $(TS)$(W)writer.c
	gcc -I$(TH) -c $(TS)$(W)writer.c -o $(O)$(W)test_module_writer.o

# Test the assignments
$(O)$(W)test_assignments.o: $(S)$(W)test_assignments.c
	gcc -I$(TH) -c $(S)$(W)test_assignments.c -o $(O)$(W)test_assignments.o

# Get the assignments module
$(O)$(W)test_module_assignments.o: $(TS)$(W)assignments.c
	gcc -I$(TH) -c $(TS)$(W)assignments.c -o $(O)$(W)test_module_assignments.o

# Test the functions
$(O)$(W)test_functions.o: $(S)$(W)test_functions.c
	gcc -I$(TH) -c $(S)$(W)test_functions.c -o $(O)$(W)test_functions.o

# Get the functions module
$(O)$(W)test_module_functions.o: $(TS)$(W)functions.c
	gcc -I$(TH) -c $(TS)$(W)functions.c -o $(O)$(W)test_module_functions.o


$(O)$(U)tabletests.o: $(CS)$(U)tabletests.c
	gcc -I$(CH) -c $(CS)$(U)tabletests.c -o $(O)$(U)tabletests.o

$(O)$(U)writertests.o: $(CS)$(U)writertests.c
	gcc -I$(CH) -c $(CS)$(U)writertests.c -o $(O)$(U)writertests.o

$(O)$(U)tests.o: $(CS)$(U)tests.c
	gcc -I$(CH) -c $(CS)$(U)tests.c -o $(O)$(U)tests.o

# Tokenizer test
$(L)libtesttokenizer.a: $(O)$(T)test_tokens.o $(O)$(T)tokens_test.o $(O)$(T)test_precomp.o $(O)$(T)precomp_test.o $(O)$(T)test_cleaner.o $(O)$(T)cleaner_test.o $(O)$(T)test_reader.o $(O)$(T)test_module_reader.o $(O)$(T)test_parser.o $(O)$(T)test_module_parser.o
	ar -rcs $(L)libtesttokenizer.a $(O)$(T)test_tokens.o $(O)$(T)tokens_test.o $(O)$(T)test_precomp.o $(O)$(T)precomp_test.o $(O)$(T)test_cleaner.o $(O)$(T)cleaner_test.o $(O)$(T)test_reader.o $(O)$(T)test_module_reader.o $(O)$(T)test_parser.o $(O)$(T)test_module_parser.o

# Compengine test
$(L)libtestcompengine.a: $(O)$(C)test_parser.o $(O)$(C)test_module_parser.o $(O)$(C)test_statements.o $(O)$(C)test_module_statements.o $(O)$(C)test_compile.o $(O)$(C)test_module_compile.o $(O)$(C)test_expressions.o $(O)$(C)test_module_expressions.o $(O)$(C)test_structure.o $(O)$(C)test_module_structure.o $(O)$(C)test_analyzer.o $(O)$(C)test_module_analyzer.o
	ar -rcs $(L)libtestcompengine.a $(O)$(C)test_parser.o $(O)$(C)test_module_parser.o $(O)$(C)test_statements.o $(O)$(C)test_module_statements.o $(O)$(C)test_compile.o $(O)$(C)test_module_compile.o $(O)$(C)test_expressions.o $(O)$(C)test_module_expressions.o $(O)$(C)test_structure.o $(O)$(C)test_module_structure.o $(O)$(C)test_analyzer.o $(O)$(C)test_module_analyzer.o

# Utils
$(L)libtestutils.a: $(O)$(U)tests.o $(O)$(U)comptests.o $(O)$(U)tabletests.o $(O)$(U)writertests.o
	ar -rcs $(L)libtestutils.a $(O)$(U)tests.o $(O)$(U)comptests.o $(O)$(U)tabletests.o $(O)$(U)writertests.o

# Table test
$(L)libtesttable.a: $(O)$(B)test_table.o $(O)$(B)test_module_table.o $(O)$(B)test_parser.o $(O)$(B)test_module_parser.o
	ar -rcs $(L)libtesttable.a $(O)$(B)test_table.o $(O)$(B)test_module_table.o $(O)$(B)test_parser.o $(O)$(B)test_module_parser.o

# Writer test
$(L)libtestwriter.a: $(O)$(W)test_loops.o $(O)$(W)test_module_loops.o $(O)$(W)test_tracker.o $(O)$(W)test_module_tracker.o $(O)$(W)test_writer.o $(O)$(W)test_module_writer.o $(O)$(W)test_assignments.o $(O)$(W)test_module_assignments.o $(O)$(W)test_functions.o $(O)$(W)test_module_functions.o
	ar -rcs $(L)libtestwriter.a $(O)$(W)test_loops.o $(O)$(W)test_module_loops.o $(O)$(W)test_tracker.o $(O)$(W)test_module_tracker.o $(O)$(W)test_writer.o $(O)$(W)test_module_writer.o $(O)$(W)test_assignments.o $(O)$(W)test_module_assignments.o $(O)$(W)test_functions.o $(O)$(W)test_module_functions.o

# Main test file
$(O)tests.o: $(S)tests.c
	gcc -I$(H) -c $(S)tests.c -o $(O)tests.o

# Executable
tests: $(O)tests.o $(L)libtesttable.a $(L)libtesttokenizer.a $(L)libtestcompengine.a $(L)libtestutils.a $(L)libtestwriter.a
	gcc -I$(TH) -L$(L) $(O)tests.o -ltesttokenizer -ltestcompengine -ltestwriter -ltesttable -ltestutils -o tests
