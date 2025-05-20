# Makefile for hw3
# Written by: Albert N. // 5/13/2025

CC = gcc
CFLAGS = -Wall -Wextra -std=c17 -Iinclude
LFLAGS = -Wall -Wextra -std=c17 $(DEBUG)
DEBUG = -O2 -DNODEBUG
#DEBUG = -g -DDEBUG

# List of source files
SRCS = src/main.c \
	   src/GetReqs.c \
	   src/ReportGen.c
# List of object files
OBJS = $(SRCS:.c=.o)

# Compile each file
%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Linker
rdgg-81013165.exe: $(OBJS)
	$(CC) $(LFLAGS) -o $@ $^

all: rdgg-81013165.exe

# Clean up directory, remove any files created
clean:
	rm -f $(OBJS) rdgg-81013165.exe

# Creates and runs the program
run: all
	./rdgg-81013165.exe

.PHONY: all clean run