#CCC = g++11
CCC = g++

#CCCFLAGS = -Wall -g -std=c++11 -lpthread -lX11
CCCFLAGS = -Wall -g -std=c++11 -lpthread

all : plc

plc : plc.o administration.o scanner.o parser.o firstSets.o symbolTable.o token.o attribute.o
	$(CCC) $(CCCFLAGS) -o $@ $^

%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

administration.o : administration.h scanner.h

scanner.o : scanner.h symbolTable.h token.h

parser.o : administration.h token.h firstSets.cc

firstSets.o : token.h

symbolTable.o	:	symbolTable.h token.h

token.o	:	token.h attribute.h symbol.h

attribute.o : attribute.h

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f plc
