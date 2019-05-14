#Samantha Schrock
#5/8/18
#makefile for Group Project
#adapted from example makefile provided by Sarah Maas on Slack
#and http://www.mrbook.org/blog/tutorials/make

CC = g++
CFLAGS = -c -Wall -std=c++0x
LFLAGS = -Wall -g -std=c++0x
PROG = predatorPrey

#Sources
SRCS = Ant.o Board.o Critter.o Doodlebug.o inputValidation.o main.o \
	Menu.o

#Objects
OBJS = $(SRCS:.cpp=o)

$(PROG): $(OBJS)
	$(CC) $(LFLAGS) $(SRCS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(PROG) $(OBJS)

