# Makefile for CSE 13S, Spring 2023, Assignment 2

# DO NOT EDIT THIS FILE

CC=clang
CFLAGS=-Wall -Wextra -Wstrict-prototypes -Werror -pedantic
LDFLAGS=-lm
OBJS=bbp.o e.o euler.o madhava.o mathlib-test.o newton.o viete.o wallis.o

.PHONY: clean format scan-build

all: mathlib-test

mathlib-test: $(OBJS)
	$(CC) $(LDFLAGS) -o mathlib-test $(OBJS)

%.o: %.c mathlib.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f mathlib-test $(OBJS)

scan-build: clean
	scan-build --use-cc=clang make

format:
	clang-format -i -style=file *.[ch]
