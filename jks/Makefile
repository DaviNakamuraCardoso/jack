
CC = clang
FLAGS = -Wall -Wextra -Wpedantic -Werror -Wparentheses

OBJ = main.o tokenizer.o tokens.o ascii.o symbols.o operators.o

O = obj/
S = src/
I = include/

OBJS = $(foreach obj, $(OBJ), $(addprefix $(O), $(obj)))

$(O)%.o: $(S)%.c
	$(CC) $(FLAGS) -I $(I) -c $^ -o $@

all:  $(OBJS)
	$(CC) $(FLAGS) $^ -o jks

test: all
	./jks file.jks

clean: 
	rm $(O)*.o
