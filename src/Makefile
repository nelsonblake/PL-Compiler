#CCC = g++11
CCC = g++

#CCCFLAGS = -Wall -g -std=c++11 -lpthread -lX11
CCCFLAGS = -Wall -g -std=c++11 -lpthread

all : plc

plc : plc.o administration.o scanner.o parser.o symbolTable.o token.o attribute.o tableEntry.o blockTable.o interp.o assembler.o
	$(CCC) $(CCCFLAGS) -o $@ $^

%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

administration.o : administration.h scanner.h

scanner.o : scanner.h symbolTable.h token.h

parser.o : administration.h token.h firstSets.h

symbolTable.o	:	symbolTable.h token.h

token.o	:	token.h attribute.h symbol.h

attribute.o : attribute.h

tableEntry.o : tableEntry.h

blockTable.o : blockTable.h tableEntry.h

interp.o : interp.h

assembler.o : assembler.h

clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f plc
