# # # # # # #
# Makefile for COMP20003 Assignment 1
#
# created Mar 2018
# Matt Farrugia <matt.farrugia@unimelb.edu.au> COMP20007
# Modified by Patrick Tjahjadi <ptjahjadi@student.unimelb.edu.au>
# Approved by Nir Lipovetzky
CC     = gcc
EXE    = dict1 dict2
OBJ    = stage1.o bstree.o stage2.o bstree2.o
#				add any new object files here ^

# top (default) target
all: dict1 dict2

# how to link executable
dict1: stage1.o bstree.o
	gcc -Wall -o dict1 stage1.o bstree.o

dict2: stage2.o bstree2.o
	gcc -Wall -o dict2 stage2.o bstree2.o

# other dependencies
stage1.o: bstree.h
bstree.o: bstree.h
stage2.o: bstree2.h 
bstree2.o: bstree2.h

# ^ add any new dependencies here

# phony targets (do not represent actual files)
.PHONY: clean cleanly all CLEAN
# `make clean` to remove all object files
# `make CLEAN` to remove all object and executable files
# `make cleanly` to `make` then immediately remove object files (inefficient)
clean:
	rm -f $(OBJ)
CLEAN: clean
	rm -f $(EXE)
cleanly: all clean
