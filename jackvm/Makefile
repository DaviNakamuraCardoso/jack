
# Paths
O = ./obj/
S = ./src/
I = ./include/

# Compiler and flags
CC = gcc 
FLAGS = -fPIE -Wall -Wextra -Ofast

# Basic VM operations
CMDS = push pop operators jumps
CMDSP = $(foreach cmd, $(CMDS), $(addprefix cmds/, $(cmd)))

# Standard Jack Library
STDJL = stdio stdjl memory string stdlib math
STDJLIB = $(foreach std, $(STDJL), $(addprefix stdlib/, $(std)))

# Main modules and objects
MODULES = main tokenizer ascii hash tokens list vm $(CMDSP) $(STDJLIB) 
OBJPATHS = $(foreach obj, $(MODULES), $(addprefix $(O), $(obj)))  
OBJECTS = $(foreach obj, $(OBJPATHS), $(addsuffix .o, $(obj)))

# Recipes
$(O)%.o: $(S)%.c
	$(CC) -I $(I) $(FLAGS) -c $^ -o $@	

all: $(OBJECTS)
	$(CC) $(FLAGS) $^ -o jackvm -lm

clean: 
	rm $(O)*.o

test:
	$(CC) tests/test.c -o tests/test
