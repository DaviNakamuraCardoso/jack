
CC = clang
FLAGS = -Wall -Wextra -Wpedantic -Werror -Wparentheses
EXEC = abcc

OBJ = main.o tokenizer.o tokens.o ascii.o symbols.o operators.o error.o

O = obj/
S = src/
I = include/

OBJS = $(foreach obj, $(OBJ), $(addprefix $(O), $(obj)))

$(O)%.o: $(S)%.c
	$(CC) $(FLAGS) -I $(I) -c $^ -o $@

all:  $(OBJS)
	$(CC) $(FLAGS) $^ -o $(EXEC)

test: all
	./$(EXEC) percent.c

clean: 
	rm $(O)*.o $(EXEC)
