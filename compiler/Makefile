# Makefile

# (L)ibraries, (S)ource, (O)bjects, (I)ncludes
L = ./lib/
S = ./src/
O = ./obj/
I = ./include/

# (T)okenizer and (C)ompilation engine
T = tokenizer/
C = compengine/
U = utils/
B = table/
W = writer/

# Precompilation functions
$(O)$(T)precomp.o: $(S)$(T)precomp.c
	gcc -I$(I) -c $(S)$(T)precomp.c -o $(O)$(T)precomp.o

# Tokens
$(O)$(T)tokens.o: $(S)$(T)tokens.c
	gcc -I$(I) -c $(S)$(T)tokens.c -o $(O)$(T)tokens.o

# Reader
$(O)$(T)reader.o: $(S)$(T)reader.c
	gcc -I$(I) -c $(S)$(T)reader.c -o $(O)$(T)reader.o

# Cleaner
$(O)$(T)cleaner.o: $(S)$(T)cleaner.c
	gcc -I$(I) -c $(S)$(T)cleaner.c -o $(O)$(T)cleaner.o

# Parser
$(O)$(T)parser.o: $(S)$(T)parser.c
	gcc -I$(I) -c $(S)$(T)parser.c -o $(O)$(T)parser.o


# Parser
$(O)$(C)parser.o: $(S)$(C)parser.c
	gcc -I$(I) -c $(S)$(C)parser.c -o $(O)$(C)parser.o

# Compile
$(O)$(C)compile.o: $(S)$(C)compile.c
	gcc -I$(I) -c $(S)$(C)compile.c -o $(O)$(C)compile.o

$(O)$(C)statements.o: $(S)$(C)statements.c
	gcc -I$(I) -c $(S)$(C)statements.c -o $(O)$(C)statements.o

# Expressions
$(O)$(C)expressions.o: $(S)$(C)expressions.c
	gcc -I$(I) -c $(S)$(C)expressions.c -o $(O)$(C)expressions.o

# Structure
$(O)$(C)structure.o: $(S)$(C)structure.c
	gcc -I$(I) -c $(S)$(C)structure.c -o $(O)$(C)structure.o

# Analyzer
$(O)$(C)analyzer.o: $(S)$(C)analyzer.c
	gcc -I$(I) -c $(S)$(C)analyzer.c -o $(O)$(C)analyzer.o


# -- Table
$(O)$(B)table.o: $(S)$(B)table.c
	gcc -I$(I) -c $(S)$(B)table.c -o $(O)$(B)table.o

$(O)$(B)parser.o: $(S)$(B)parser.c
	gcc -I$(I) -c $(S)$(B)parser.c -o $(O)$(B)parser.o

# -- Writer
$(O)$(W)loops.o: $(S)$(W)loops.c
	gcc -I$(I) -c $(S)$(W)loops.c -o $(O)$(W)loops.o

# Tracker
$(O)$(W)tracker.o: $(S)$(W)tracker.c
	gcc -I$(I) -c $(S)$(W)tracker.c -o $(O)$(W)tracker.o

# Writer functions
$(O)$(W)writer.o: $(S)$(W)writer.c
	gcc -I$(I) -c $(S)$(W)writer.c -o $(O)$(W)writer.o

# Assignments
$(O)$(W)assignments.o: $(S)$(W)assignments.c
	gcc -I$(I) -c $(S)$(W)assignments.c -o $(O)$(W)assignments.o

# Functions
$(O)$(W)functions.o: $(S)$(W)functions.c
	gcc -I$(I) -c $(S)$(W)functions.c -o $(O)$(W)functions.o
	
# Error handler
$(O)$(U)error.o:
	gcc -I$(I) -c $(S)$(U)error.c -o $(O)$(U)error.o

$(O)$(U)strutils.o:
	gcc -I$(I) -c $(S)$(U)strutils.c -o $(O)$(U)strutils.o


# Utils
$(L)libdccutils.a: $(O)$(U)error.o $(O)$(U)strutils.o
	ar -rcs $(L)libdccutils.a $(O)$(U)error.o $(O)$(U)strutils.o

# Tokenizer library
$(L)libtokenizer.a: $(O)$(T)tokens.o $(O)$(T)parser.o $(O)$(T)precomp.o $(O)$(T)reader.o $(O)$(T)cleaner.o
	ar -rcs $(L)libtokenizer.a $(O)$(T)tokens.o $(O)$(T)parser.o $(O)$(T)precomp.o $(O)$(T)reader.o $(O)$(T)cleaner.o

# Compilation Engine Library
$(L)libcompengine.a: $(O)$(C)parser.o $(O)$(C)compile.o $(O)$(C)statements.o $(O)$(C)expressions.o $(O)$(C)structure.o $(O)$(C)analyzer.o
	ar -rcs $(L)libcompengine.a $(O)$(C)parser.o $(O)$(C)compile.o $(O)$(C)statements.o $(O)$(C)expressions.o $(O)$(C)structure.o $(O)$(C)analyzer.o

# Symbol Table library
$(L)libtable.a: $(O)$(B)parser.o $(O)$(B)table.o
	ar -rcs $(L)libtable.a $(O)$(B)table.o $(O)$(B)parser.o

# Code Writer Library
$(L)libwriter.a: $(O)$(W)loops.o $(O)$(W)tracker.o $(O)$(W)writer.o $(O)$(W)assignments.o $(O)$(W)functions.o
	ar -rcs $(L)libwriter.a $(O)$(W)loops.o $(O)$(W)tracker.o $(O)$(W)writer.o $(O)$(W)assignments.o $(O)$(W)functions.o

# Main module
$(O)dcc.o: $(S)dcc.c
	gcc -I$(I) -c $(S)dcc.c -o $(O)dcc.o

# Executable
dcc: $(O)dcc.o $(L)libcompengine.a $(L)libtable.a $(L)libtokenizer.a $(L)libdccutils.a $(L)libwriter.a
	gcc -Ofast -I$(I) -L$(L) $(O)dcc.o -lcompengine -lwriter -ltable -ltokenizer -ldccutils -o dcc
