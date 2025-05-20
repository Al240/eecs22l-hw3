# Makefile for hw3
# Written by: Albert N. // 5/13/2025

CC = gcc
CFLAGS = -Wall -std=c17 -c
LFLAGS = -Wall -std=c17 $(DEBUG)
DEBUG = -O2 -DNODEBUG
#DEBUG = -g -DDEBUG

# List of source files
SRCS = main.c \
	   list.c \
	   stack.c \
	   queue.c \
	   tree.c \
	   graph.c
# List of object files
OBJS = $(SRCS:.c=.o)

all:

clean:

_PHONY: all clean run
