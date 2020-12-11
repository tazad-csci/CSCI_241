#
# PROGRAM:  assign4
# DATE DUE: 3/19/19
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign4: assign4.o Matrix.o Matrix.o
	g++ $(CCFLAGS) -o assign4 assign4.o  Matrix.o

# Rules to compile source code files to object code
assign4.o: assign4.cpp Matrix.h
	g++ $(CCFLAGS) -c assign4.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ $(CCFLAGS) -c Matrix.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ $(CCFLAGS) -c Matrix.cpp

Matrix.h: Matrix.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign4
