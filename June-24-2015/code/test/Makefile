NARRAYTESTSRC=narray_test.cpp narray_construction_test.cpp \
			  narray_access_test.cpp narray_assignment_test.cpp \
			  narray_old_functions_test.cpp \
			  narray_old_operators_test.cpp \
			  earray_sin_test.cpp \
			  earray_add_test.cpp \
			  earray_sub_test.cpp \
			  earray_mult_test.cpp \
			  earray_div_test.cpp  \
			  earray_cos_test.cpp

NARRAYTESTOBJ=$(patsubst %.cpp,%.o,$(NARRAYTESTSRC))

CXXFLAGS=-std=c++11 -O3 -g -Wall -pedantic -Wextra
all: narray_test

narray_test: $(NARRAYTESTOBJ)
	$(CXX) $(CXXFLAGS) -o$@ $(NARRAYTESTOBJ) -lboost_unit_test_framework

$(NARRAYTESTOBJ):%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< 

.PHONY: clean test

clean:
	rm -rf *.o
	rm -rf narray_test


test: narray_test
	./narray_test
