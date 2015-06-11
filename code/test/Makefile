NARRAYTESTSRC=narray_test.cpp narray_construction_test.cpp
NARRAYTESTOBJ=$(patsubst %.cpp,%.o,$(NARRAYTESTSRC))

CXXFLAGS=-std=c++11 -O3 -g
all: narray_test

narray_test: $(NARRAYTESTOBJ)
	$(CXX) $(CXXFLAGS) -o$@ $(NARRAYTESTOBJ) -lboost_unit_test_framework

$(NARRAYTESTOBJ):%.o:%.cpp
	$(CXX) $(CXXFLAGS) -c $< 

.PHONY: clean

clean:
	rm -rf *.o
	rm -rf narray_test
