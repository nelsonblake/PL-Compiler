#CCC = g++11
CCC = g++

#CCCFLAGS = -Wall -g -std=c++11 -lpthread -lX11
CCCFLAGS = -Wall -g -std=c++11 -lpthread

all : plc

plc : plc.o symbolTable.o token.o attribute.o
	$(CCC) $(CCCFLAGS) -o $@ $^

%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

symbolTable.o	:	symbolTable.h token.h

token.o	:	token.h attribute.h symbol.h

attribute.o : attribute.h

clean:
	rm -f *.o *~ *% *# .#*

clean-all:
	rm -f plc
