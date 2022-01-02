CC = clang

%.o: %.c
	$(CC) -c $^ -o $@

all: keywords.o main.o
	$(CC) $^ -o test
