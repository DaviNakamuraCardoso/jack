# (S)ources, (H)eaders, (O)bjects, (A)rchives

S = ./src
I = ./includes
O = ./obj
L = ./libs/

T = /tests/
D = /dmus/

# Tested source and tested headers

TS = ../src
TI = ../includes

TJ = /jukebox/
TJT = /jukebox/test

TG = /storage/
TT = /tools/


# Specs
CC = gcc
FLAGS = -Wall -Ofast

# OBJECTS
DMUS = tests.o testtools.o
DMUSOBJS = $(foreach obj, $(DMUS), $(addprefix $(D), $(obj)))

TESTS = run.o error.o
TESTOBJS = $(foreach obj, $(TESTS), $(addprefix $(T), $(obj)))

STORAGE = files.o logfiles.o
STOROBJS = $(foreach obj, $(STORAGE), $(addprefix $(TG), $(obj)))

JUKEBOX = queue.o
JUKEOBJS = $(foreach obj, $(JUKEBOX), $(addprefix $(TJ), $(obj)))
TJUKEOBJS = $(foreach obj, $(JUKEBOX), $(addprefix $(TJT), $(obj)))

TOOLS = error.o
TOOLSOBJS = $(foreach obj, $(TOOLS), $(addprefix $(TT), $(obj)))

OBJECTS = $(DMUSOBJS)
OBJS = $(foreach obj, $(OBJECTS), $(addprefix $(O), $(obj)))

TESTEDOBJS = $(STOROBJS) $(TOOLSOBJS) $(JUKEOBJS)

# Libraries
$(L)libtests.a: $(foreach obj, $(TESTOBJS), $(addprefix $(O), $(obj)))
	ar -rcs $@ $^

$(L)libtested.a: $(foreach obj, $(TESTEDOBJS), $(addprefix $(O), $(obj)))
	ar -rcs $@ $^

$(L)libjuketests.a: $(foreach obj, $(TJUKEOBJS), $(addprefix $(O), $(obj)))
	ar -rcs $@ $^

LIBS = libtests.a libtested.a libjuketests.a
LIBRARIES = $(foreach lib, $(LIBS), $(addprefix $(L), $(lib)))
LINKS = -ltests -ltested -ljuketests

all: $(OBJS) $(LIBRARIES)
	$(CC) -L$(L) $(FLAGS) $(OBJS) $(LINKS) -o tests

# Main
./obj/%.o: ./src/%.c
	$(CC) -I$(I) -I$(TI) $(FLAGS) -c $^ -o $@

./obj/%.o: ../src/%.c
	$(CC) -I$(TI) $(FLAGS) -c $^ -o $@
