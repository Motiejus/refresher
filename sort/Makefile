CFLAGS = -g -Wall -Wextra -pedantic

ALL_C = insertion quick heap
ALL_PY = $(wildcard *.py)

.PHONY: all test

all: $(ALL_C)

insertion: insertion.o main.o

quick: quick.o main.o

heap: heap.o main.o

test: $(ALL_C)
	./test.sh $(ALL_C) $(ALL_PY)
