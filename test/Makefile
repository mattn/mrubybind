
INC=-I $(MRUBY)/include -I ..
LIB=-L $(MRUBY)/build/host/lib -lmruby

MRUBYBIND_SRCDIR=..
MRUBYBIND_OBJ=mrubybind.o

SRCS=$(wildcard *.cc)
EXES=$(SRCS:%.cc=%)

all:	$(EXES)

clean:
	rm -rf *.o $(EXES)

test:	$(EXES)
	./test.sh

%.o:	%.cc
	g++ -c -o $@ $(INC) $<

mrubybind.o:	$(MRUBYBIND_SRCDIR)/mrubybind.cc
	g++ -c -o $@ $(INC) $<

int:	int.o $(MRUBYBIND_OBJ)
	g++ -o $@ $^ $(LIB)

float:	float.o $(MRUBYBIND_OBJ)
	g++ -o $@ $^ $(LIB)

string:	string.o $(MRUBYBIND_OBJ)
	g++ -o $@ $^ $(LIB)

class:	class.o $(MRUBYBIND_OBJ)
	g++ -o $@ $^ $(LIB)

module:	module.o $(MRUBYBIND_OBJ)
	g++ -o $@ $^ $(LIB)

#