# build an executable named circularqueue
all: linkedlist.cpp
	g++ -g -Wall -o LL linkedlist.cpp

clean:
	$(RM) LL
