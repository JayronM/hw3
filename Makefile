CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test stack_test	heap_test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------

llrec.o:  llrec.cpp llrec.h
	$(CXX)	$(CXXFLAGS)	$(DEFS)	-o	$@	-c	llrec.cpp
llrec-test.o: llrec-test.cpp  llrec.h
	$(CXX)	$(CXXFLAGS)	$(DEFS)	-o	$@	-c	llrec-test.cpp
llrec-test: llrec.o llrec-test.o
	$(CXX)	$(CXXFLAGS)	-o	llrec-test	llrec.o	llrec-test.o
stack_test.o: stack_test.cpp stack.h
	$(CXX)	$(CXXFLAGS)	-o	$@	-c	stack_test.cpp
stack_test:	stack_test.o
	$(CXX)	$(CXXFLAGS)	-o	stack_test	stack_test.o
heap_test.o:	heap_test.cpp	heap.h
	$(CXX)	$(CXXFLAGS)	-o	$@	-c	heap_test.cpp
heap_test:	heap_test.o
	$(CXX)	$(CXXFLAGS)	-o	heap_test	heap_test.o
clean:
	rm -f *.o rh llrec-test *~

.PHONY: clean 