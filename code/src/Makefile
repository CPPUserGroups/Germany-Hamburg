F90=gfortran
F90FLAGS=-O3 
BMFLAGS=-std=c++11 -O3 -g -Wall -pedantic -Wextra

all: fortran_test check_types bm_cstyle bm_classic

fortran_test:fortran_test.f90
	$(F90) $(F90FLAGS) -o$@ $<

check_types:check_types.cpp
	c++ -std=c++11 -O0 -g -o$@ $<

bm_cstyle: bm_cstyle.cpp
	c++ $(BMFLAGS) -o$@ $<

bm_classic: bm_classic.cpp
	c++ $(BMFLAGS) -o$@ $<



.PHONY: clean

clean:
	rm -rf *.o
	rm -rf fortran_test
	rm -rf check_types
	rm -rf bm_cstyle
	rm -rf bm_classic
