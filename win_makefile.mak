# win_makefile.mak

# By Group 8:
#  Kamren M. Gregory - 3759472
#  Anush Matevosyan - 3758790
#  Sharmila Sadia Ahmed - 3741966

# To run:
#  $ make -f makefile.mak
#  $ make clean -f makefile.mak

SRCDIR = src
BINDIR = bin

SRCS = $(wildcard $(SRCDIR)/*.c)
HDRS = $(wildcard $(SRCDIR)/*.h)
OBJS = $(SRCS:$(SRCDIR)/%.c=$(BINDIR)/%.o) # OBJS = bin/main.o, etc.

GCC = gcc
CFLAGS = -g -Wall -Wshadow

all: $(BINDIR) $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o prog

$(BINDIR):
	mkdir $(BINDIR)

$(BINDIR)/%.o: $(SRCDIR)/%.c 
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	del $(BINDIR)
	del prog.exe
	del *.csv