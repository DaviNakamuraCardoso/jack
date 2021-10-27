
# Compiler and flags
CC = clang
FLAGS = -Wall -Werror -Wextra -pedantic -I ./include

# Paths
S = ./src/
O = ./obj/



CP = compiler/
COMPILER = compiler
CMP = $(foreach src, $(COMPILER), $(addprefix $(CP), $(src)))


OBJECTS = main $(CMP)
OBJP = $(foreach obj, $(OBJECTS), $(addprefix $(O), $(obj)))
OBJ = $(foreach obj, $(OBJP), $(addsuffix .o, $(obj)))


$(O)%.o: $(S)%.c
	$(CC) $(FLAGS) -c $^ -o $@

all: $(OBJ)
	$(CC) $(FLAGS) $^ -o script

clean:
	rm $(OBJ)


