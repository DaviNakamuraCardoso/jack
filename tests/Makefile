# (S)ources, (H)eaders, (O)bjects, (A)rchives

S = ./src
I = ./includes
O = ./obj
L = ./libs/

T = /tests/
D = /dmus/

# Tested source and tested headers

TS = ../src
TH = ../includes


# Specs
CC = gcc
FLAGS = -Wall -Ofast

# OBJECTS
DMUS = tests.o
DMUSOBJS = $(foreach obj, $(DMUS), $(addprefix $(D), $(obj)))

TESTS = run.o
TESTOBJS = $(foreach obj, $(TESTS), $(addprefix $(T), $(obj)))

OBJECTS = $(DMUSOBJS)
OBJS = $(foreach obj, $(OBJECTS), $(addprefix $(O), $(obj)))

# Libraries
$(L)libtests.a: $(foreach obj, $(TESTOBJS), $(addprefix $(O), $(obj)))
	ar -rcs $@ $^

LIBS = libtests.a
LIBRARIES = $(foreach lib, $(LIBS), $(addprefix $(L), $(lib)))

all: $(OBJS) $(LIBRARIES)
	$(CC) -L$(L) $(FLAGS) $(OBJS) -ltests -o tests

$(O)$(D)%.o: $(S)$(D)%.c
	$(CC) -I$(I) $(FLAGS) -c $^ -o $@

$(O)$(T)%.o: $(S)$(T)%.c
	$(CC) -I$(I) $(FLAGS) -c $^ -o $@
