F90=gfortran
F90FLAGS=-O3 
BMFLAGS=-std=c++11 -O3 -g -Wall -pedantic -Wextra

all: sinbm_classic sinbm_cstyle sinbm_et \
	 ang2q_cstyle ang2q_classic ang2q_et

sinbm_cstyle: sinbm.cpp
	c++ $(BMFLAGS) -DCSTYLE -o$@ $<

sinbm_classic: sinbm.cpp
	c++ $(BMFLAGS) -DCLASSICOPERATORS -o$@ $<

sinbm_et:sinbm.cpp
	c++ $(BMFLAGS) -DEXPTOPERATORS -o$@ $<

ang2q_cstyle: ang2q.cpp
	c++ $(BMFLAGS) -DCSTYLE -o$@ $<

ang2q_classic: ang2q.cpp
	c++ $(BMFLAGS) -DCLASSICOPERATORS -o$@ $<

ang2q_et: ang2q.cpp
	c++ $(BMFLAGS) -DEXPTOPERATORS -o$@ $<

.PHONY: clean all

clean:
	rm -rf *.o
	rm -rf sinbm_cstyle
	rm -rf sinbm_classic
	rm -rf sinbm_et
	rm -rf ang2q_cstyle
	rm -rf ang2q_classic
	rm -rf ang2q_et
