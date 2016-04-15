CXXFLAGS=-std=c++11 -Wall $(shell python3-config --cflags) -UNDEBUG -g
LDFLAGS=$(shell python3-config --ldflags)

embed: embed.o oneclass.o
	g++ -o $@ $? ${LDFLAGS}

#embed: embed.cpp
#	g++ -std=c++11 -Wall $(shell python3-config --cflags)  -UNDEBUG -g -o $@ $< $(shell python3-config --ldflags)
