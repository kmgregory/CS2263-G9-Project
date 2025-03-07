# makefile.mak

# By Group 8:
#  Kamren M. Gregory - 3759472
#  Anush Matevosyan - 3758790
#  Sharmila Sadia Ahmed - 3741966

# To run:
#	* MUST HAVE A bin/ DIRECTORY IN STRUCTURE *
#  CS2263-G8-Project/
#	|-> src/
#	└-> bin/
#  
#  $ make bin/<filename>.o -f makefile.mak
#  $ make program -f makefile.mak
#  $ make clean -f makefile.mak

GCC = gcc
CFLAGS = -g -Wall -Wshadow
SRCS = src/main.c
# HDRS = ___.h - No header files yet
OBJS = $(SRCS:src/%.c=bin/%.o) # OBJS = bin/main.o, etc.
VALGRIND = valgrind --tool=memcheck --leak-check=full
VALGRIND+ = --verbose --log-file=valog

# Compile source files to object files in bin
# $< is the source file (src/%.c)
# $@ is the target file (bin/%.o)
bin/%.o: src/%.c
	$(GCC) $(CFLAGS) -c $< -o $@ 

# Compile and link the program
program:
	$(GCC) $(CFLAGS) $(OBJS) -o program

# Implicit rule for object files
.c.o:
	$(GCC) $(CFLAGS) -c $*.c

# Clean object files and the program
clean:
	rm -f bin/*.o program *~ *bak output*

