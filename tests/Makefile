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

TOOLS = error.o
TOOLSOBJS = $(foreach obj, $(TOOLS), $(addprefix $(TT), $(obj)))

OBJECTS = $(DMUSOBJS)
OBJS = $(foreach obj, $(OBJECTS), $(addprefix $(O), $(obj)))

TESTEDOBJS = $(STOROBJS) $(TOOLSOBJS)

# Libraries
$(L)libtests.a: $(foreach obj, $(TESTOBJS), $(addprefix $(O), $(obj)))
	ar -rcs $@ $^

$(L)libtested.a: $(foreach obj, $(TESTEDOBJS), $(addprefix $(O), $(obj)))
	ar -rcs $@ $^

LIBS = libtests.a libtested.a
LIBRARIES = $(foreach lib, $(LIBS), $(addprefix $(L), $(lib)))

all: $(OBJS) $(LIBRARIES)
	$(CC) -L$(L) $(FLAGS) $(OBJS) -ltests -o tests

# Main
$(O)$(D)%.o: $(S)$(D)%.c
	$(CC) -I$(I) $(FLAGS) -c $^ -o $@

# Tests
$(O)$(T)%.o: $(S)$(T)%.c
	$(CC) -I$(I) -I$(TI) $(FLAGS) -c $^ -o $@

# Storage
$(O)$(TG)%.o: $(TS)$(TG)%.c
	$(CC) -I$(TI) $(FLAGS) -c $^ -o $@

# Tools
$(O)$(TT)%.o: $(TS)$(TT)%.c
	$(CC) -I$(TI) $(FLAGS) -c $^ -o $@
