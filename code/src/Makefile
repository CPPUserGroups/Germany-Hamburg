F90=gfortran
F90FLAGS=-O3 

all: fortran_test check_types

fortran_test:fortran_test.f90
	$(F90) $(F90FLAGS) -o$@ $<

check_types:check_types.cpp
	c++ -std=c++11 -O0 -g -o$@ $<

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf fortran_test
	rm -rf check_types
