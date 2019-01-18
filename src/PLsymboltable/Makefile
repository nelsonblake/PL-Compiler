#CCC = g++11
CCC = g++

#CCCFLAGS = -Wall -g -std=c++11 -lpthread -lX11
CCCFLAGS = -Wall -g -std=c++11 -lpthread

%.o : %.cc
	$(CCC) -c $(CCCFLAGS) $<

symbolTable.o : symbolTable.h
symbolTableEntry.o : symbolTableEntry.h
token.o : attribute.h token.h

clean:
	rm -f *.o *~ *% *# .#*
