F90=gfortran
F90FLAGS=-O3 

all: fortran_test

fortran_test:fortran_test.f90
	$(F90) $(F90FLAGS) -o$@ $<

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf fortran_test
