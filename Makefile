
S = ./src
O = ./obj
I = ./includes/
L = ./libs/


D = /dmus/
J = /jukebox/
T = /tools/
G = /storage/

CC = gcc
FLAGS = -Ofast -Wall


# Modules
DMUS = dmus.o
DMUSOBJS = $(foreach obj, $(DMUS), $(addprefix $(D), $(obj)))

JUKEBOX = player.o queue.o
JUKEOBJS = $(foreach obj, $(JUKEBOX), $(addprefix $(J), $(obj)))

TOOLS = error.o
TOOLOBJS = $(foreach obj, $(TOOLS), $(addprefix $(T), $(obj)))

STORAGE = files.o logfiles.o
STOROBJS = $(foreach obj, $(STORAGE), $(addprefix $(G), $(obj)))

OBJS = $(DMUSOBJS)
OBJECTS = $(foreach obj, $(OBJS), $(addprefix $(O), $(obj)))


# Archives
$(L)libjukebox.a: $(foreach obj, $(JUKEOBJS), $(addprefix $(O), $(obj)))
	ar -rcs $@ $^

$(L)libtools.a: $(foreach obj, $(TOOLOBJS), $(addprefix $(O), $(obj)))
	ar -rcs $@ $^

$(L)libstorage.a: $(foreach obj, $(STOROBJS), $(addprefix $(O), $(obj)))
	ar -rcs $@ $^

LIBS = $(L)libjukebox.a $(L)libtools.a $(L)libstorage.a

# Main

all: $(OBJECTS) $(LIBS)
	$(CC) -I$(I) -L$(L) $(FLAGS) $(OBJECTS) -ljukebox -lstorage -ltools -o mus

# Definitions

$(O)$(D)%.o: $(S)$(D)%.c
	$(CC) -I$(I) -c $^ -o $@

$(O)$(J)%.o: $(S)$(J)%.c
	$(CC) -I$(I) -c $^ -o $@

$(O)$(G)%.o: $(S)$(G)%.c
	$(CC) -I$(I) -c $^ -o $@

$(O)$(T)%.o: $(S)$(T)%.c
	$(CC) -I$(I) -c $^ -o $@
