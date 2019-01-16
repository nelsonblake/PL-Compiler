#CCC = g++11
CCC = g++

#CCCFLAGS = -Wall -g -std=c++11 -lpthread -lX11
CCCFLAGS = -Wall -g -std=c++11 -lpthread

all : main

main : main.o symbol.o
	$(CCC) $(CCCFLAGS) -o $@ $^

%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

symbol.o : symbol.h

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f main