CC = gcc
CFLAGS  = -std=c11 -g -Wall
SRC = main.c incidencia.c
OBJS := $(SRC:.c=.o)
EXE = test-incidencia

all: $(EXE)

run: $(EXE)
	./$<

run_v: $(EXE)
	valgrind ./$<

$(EXE): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@
	@rm -f $(OBJS)

$(OBJS): $(SRC)

.PHONY: clean

clean:
	rm -f $(EXE)
