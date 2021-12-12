
CC = clang
FLAGS = -Wall -Wextra

OBJ = main.o tokenizer.o tokens.o ascii.o symbols.o operators.o

%.o: %.c
	$(CC) $(FLAGS) -c $^ -o $@

all:  $(OBJ)
	$(CC) $(FLAGS) $^ -o jks

test: all
	./jks file.jks

clean: 
	rm *.o
