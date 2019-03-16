-include objects.mk 
CPP = clang -Wall -g -O2 -std=c++17
SRC := . #src
INC = ../include
LIB := ../lib
MINELIB = $(LIB)/*.a
MINEINC = -I$(INC)

MAINLS = $(shell ls *.cpp)
MAINLIST = $(MAINLS:%.cpp=%.out)
SRCLS = $(shell ls *.cpp)
SRCLIST = $(SRCLS:%.cpp=../lib/lib%.a)

all: $(SRCLIST)

../lib/lib%.a: %.cpp $(INC)/%.hpp
	$(CPP) -c $< $(MINEINC) -o $@

clean:
	@echo " * clean up"
	rm -rf lib/*.a *.out*

FORCE:
.FHONY: all clean FORCE
