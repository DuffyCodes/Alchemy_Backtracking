ifeq ($(OS),Windows_NT)
#
# Flags for Windows compilers
CPPFLAGS=-g -std=c++11 -MMD -D_GLIBCXX_DEBUG -Wall
LFLAGS=
RM=del /q
EXE=.exe
else
#
# Flags for Linux & OS/X
CPPFLAGS=-g -std=c++11 -MMD -fsanitize=address -D_GLIBCXX_DEBUG -Wall
LFLAGS=-pthread
RM=/bin/rm -rf
EXE=
endif
#
####################################################
# Customization for this project
#
TARGET=alchemy$(EXE)
CPPS=$(wildcard *.cpp)
DEPENDENCIES = $(CPPS:%.cpp=%.d)
OBJS = $(CPPS:%.cpp=%.o)
TESTOBJS=generator.o
#

#
########################################################################
# Macro definitions for "standard" C and C++ compilations
#
#
CC=gcc
CXX=g++
CFLAGS=-g
LINK=g++ $(CPPFLAGS)
#
#
#
#  In most cases, you should not change anything below this line.
#
#  The following is "boilerplate" to set up the standard compilation
#  commands:
#


%.d: %.cpp
	touch $@

%.o: %.cpp
	$(CXX) $(CPPFLAGS) -o $@ -c $*.cpp

#
# Targets:
#

all: $(TARGET) 

#all: generator$(EXE) $(TARGET) 

$(TARGET): $(OBJS)
	$(LINK) $(FLAGS) -o $@ $^ $(LFLAGS)

generator$(EXE): $(TESTOBJS)
	$(LINK) $(FLAGS) -o $@ $^ $(LFLAGS)


# Convenience target for use with Code::Blocks
Debug: all

docs: documentation

clean:
	-$(RM) *.o $(TARGET) generator$(EXE) docs

cleanDebug: clean

documentation:
	-mkdir docs
	doxygen Doxyfile

make.dep: $(DEPENDENCIES)
	-cat $(DEPENDENCIES) > $@

#include make.dep
findMaxTemp.o: findMaxTemp.cpp reaction.h
alchemy.o: alchemy.cpp reaction.h


