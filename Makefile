# Makefile for DMus Music Player

# (S)ource, (L)ibraries and (I)ncludes
S = ./src/
L = ./libs/
I = ./includes/


$(L)files.o: $(S)files.c
	gcc -I$(I) -c $(S)files.c -o $(L)files.o

$(L)error.o: $(S)error.c
	gcc -I$(I) -c $(S)error.c -o $(L)error.o

$(L)player.o: $(S)player.c
	gcc -I$(I) -c $(S)player.c -o $(L)player.o

$(L)logfiles.o: $(S)logfiles.c
	gcc -I$(I) -c $(S)logfiles.c -o $(L)logfiles.o

$(L)libsongutils.a: $(L)files.o $(L)error.o $(L)player.o $(L)logfiles.o
	ar -rcs $(L)libsongutils.a $(L)files.o $(L)error.o $(L)player.o $(L)logfiles.o

$(L)queue.o: $(S)queue.c
	gcc -I$(I) -c $(S)queue.c -o $(L)queue.o

$(L)main.o: $(S)main.c
	gcc -I$(I) -c $(S)main.c -o $(L)main.o

dmus: $(L)main.o $(L)libsongutils.a $(L)queue.o
	gcc $(L)queue.o $(L)main.o -I$(I) -L$(L) -lsongutils  -o dmus
