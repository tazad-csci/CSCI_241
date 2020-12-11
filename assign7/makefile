#
# PROGRAM:  assign7
# DATE DUE: 4/18/19
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign7: assign7.o 
	g++ $(CCFLAGS) -o assign7 assign7.o 

# Rules to compile source code files to object code
assign7.o: assign7.cpp Queue.h
	g++ $(CCFLAGS) -c assign7.cpp

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign7
