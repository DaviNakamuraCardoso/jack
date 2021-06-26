# (S)ources, (H)eaders, (O)bjects, (A)rchives

S = ./src
H = ./includes
O = ./obj
A = ./libs

# Tested source and tested headers

TS = ../src
TH = ../includes


# Specs
CC = gcc
FLAGS = -Wall -Ofast

%.o: %.c
	$(CC) $(FLAGS) $<

TESTOBJS = 

tests: $(TESTOBJS)
	$(CC) $(FLAGS) -o tests
