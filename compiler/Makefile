# Makefile

# (L)ibraries, (S)ource, (O)bjects, (I)ncludes
L = ./lib/
S = ./src/
O = ./obj/
I = ./include/

# (T)okenizer and (C)ompilation engine
T = tokenizer/
C = compengine/
U = utils/
B = table/
W = writer/

CC = gcc
FLAGS = -Wall


$(O)%.o: $(S)%.c
	$(CC) -I $(I) $(FLAGS) -c $^ -o $@

TOKENIZER = cleaner parser reader precomp tokens
TKROBJS = $(foreach program, $(TOKENIZER), $(addprefix $(T), $(program))) 

COMPENGINE = analyzer compile expressions parser statements structure 
CPEOBJS = $(foreach program, $(COMPENGINE), $(addprefix $(C), $(program))) 

UTILS = error strutils 
UTLOBJS = $(foreach program, $(UTILS), $(addprefix $(U), $(program))) 

TABLE = parser table
TBOBJS = $(foreach program, $(TABLE), $(addprefix $(B), $(program))) 

WRITER = assignments functions loops tracker writer 
WRTOBJS = $(foreach program, $(WRITER), $(addprefix $(W), $(program))) 

OBJECTS = $(TKROBJS) $(CPEOBJS) $(UTLOBJS) $(TBOBJS) $(WRTOBJS) dcc
OBJSP = $(foreach obj, $(OBJECTS), $(addsuffix .o, $(obj)))
OBJS = $(foreach obj, $(OBJSP), $(addprefix $(O), $(obj)))


all: $(OBJS)
	$(CC) $(FLAGS) $^ -o dcc

clean: 
	rm $(OBJS) 



