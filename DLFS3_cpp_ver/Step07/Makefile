CC = g++
CXXFLAGS = -Wall -O2
SRCS = $(filter-out step07_03.cpp, $(wildcard *.cpp))
OBJS = $(SRCS:.cpp=.o)
OUTS = $(OBJS:.o=.out)

all: $(OUTS)

%.o: %.cpp %.hpp
	$(CC) $(CXXFLAGS) -c $<

%.out: %.o
	$(CC) $< $(CXXFLAGS) -o $@

.PHONY: clean
clean: 
	rm -f $(OBJS) $(OUTS)