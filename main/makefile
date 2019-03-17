-include ../objects.mk 
CPP = clang -Wall -g -O2
#CPP = g++ -Wall -g -O2
SRC = ../src
INC = ../include
LIB = ../lib
MINELIB = -L$(LIB)
MINEINC = -I$(INC)

SRCLS = $(shell ls ../src/*.cpp)
SRCLIST = $(SRCLS:../src/%.cpp=../lib/lib%.a)
LIBLIST = $(SRCLS:../src/%.cpp=-l%)
MAINLS = $(shell ls *.cpp)
MAINLIST = $(MAINLS:%.cpp=../%.out)

all: $(MAINLIST)


../%.out: %.cpp
	$(CPP) -std=c++17 -lc++ \
	$< $(MINEINC) $(MINELIB) \
	$(LIBS) \
	$(LIBLIST) \
	-o $@;

clean:
	@echo " * clean up"
	rm -rf lib/*.a *.out*

FORCE:
.FHONY: all clean FORCE
