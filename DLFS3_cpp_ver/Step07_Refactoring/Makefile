CC = g++
CXXFLAGS = -Wall -O2
SRCS = $(filter-out step07_03.cpp, $(wildcard *.cpp), $(wildcard main.cpp))
OBJS = $(SRCS:.cpp=.o)
TARGET = main.out

#main.out: function.o function_inherited.o variable.o
#	$(CC) $(CXXFLAGS) -o main.out main.cpp function.o function_inherited.o variable.o

main.out: function.o variable.o
	$(CC) $(CXXFLAGS) -o main.out main.cpp function.o variable.o

function.o: function.cpp function.h
	$(CC) $(CXXFLAGS) -c -o function.o function.cpp

# function_inherited.o: function_inherited.cpp function_inherited.h function.h
#	$(CC) $(CXXFLAGS) -c -o function_inherited.o function_inherited.cpp

variable.o: variable.cpp variable.h
	$(CC) $(CXXFLAGS) -c -o variable.o variable.cpp

.PHONY: clean
clean: 
	rm -f $(OBJS) $(OUTS)