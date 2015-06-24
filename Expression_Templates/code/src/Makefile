F90=gfortran
F90FLAGS=-O3 
BMFLAGS=-std=c++11 -O3 -g -Wall -pedantic -Wextra

all: ang2q_cstyle ang2q_classic ang2q_et

ang2q_cstyle: ang2q.cpp
	c++ $(BMFLAGS) -DCSTYLE -o$@ $<

ang2q_classic: ang2q.cpp
	c++ $(BMFLAGS) -DCLASSICOPERATORS -o$@ $<

ang2q_et: ang2q.cpp
	c++ $(BMFLAGS) -DEXPTOPERATORS -o$@ $<

.PHONY: clean all benchmark

benchmark:
	./ang2q_cstyle `calc 1024*1024*100` 5
	./ang2q_classic `calc 1024*1024*100` 5
	./ang2q_et `calc 1024*1024*100` 5

clean:
	rm -rf *.o
	rm -rf ang2q_cstyle
	rm -rf ang2q_classic
	rm -rf ang2q_et
