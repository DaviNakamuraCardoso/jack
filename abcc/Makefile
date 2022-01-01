
CC = clang
FLAGS = -Wall -Wextra -Wpedantic -Werror -Wparentheses 
EXEC = abcc

OBJ = main.o tokenizer.o tokens.o ascii.o symbols.o operators.o error.o optree.o skip.o macrotable.o preprocessor.o

O = obj/
S = src/
I = include/

TP = test-

OBJS = $(foreach obj, $(OBJ), $(addprefix $(O), $(obj)))
TOBJS = $(foreach obj, $(OBJ), $(addprefix $(O)$(TP), $(obj))) 

$(O)%.o: $(S)%.c
	$(CC) $(FLAGS) -I $(I) -c $^ -o $@

$(O)$(TP)%.o: $(S)%.c
	$(CC) $(FLAGS) -DTOKENIZER_TEST=1 -I $(I) -c $^ -o $@

all: $(OBJS)
	$(CC) $(FLAGS) $^ -o $(EXEC)

testall: $(TOBJS)
	$(CC) $^ -o $(TP)$(EXEC)

test: testall
	for i in test/tok/*.c; do echo "$$i"; ./$(TP)$(EXEC) $$i; done

clean: 
	rm $(O)*.o $(EXEC)
