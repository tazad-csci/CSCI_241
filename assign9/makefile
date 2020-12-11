#
# PROGRAM:  assign9
# DATE DUE: 5/1/19
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign9: assign9.o Circle.o Rectangle.o Shape.o Triangle.o
	g++ $(CCFLAGS) -o assign9 assign9.o Circle.o Rectangle.o Shape.o Triangle.o
   
# Rules to compile source code files to object code
assign9.o: assign9.cpp Circle.h Rectangle.h Shape.h Triangle.h
	g++ $(CCFLAGS) -c assign9.cpp
      
Circle.o: Circle.cpp Circle.h
	g++ $(CCFLAGS) -c Circle.cpp

Rectangle.o: Rectangle.cpp Rectangle.h
	g++ $(CCFLAGS) -c Rectangle.cpp

Shape.o: Shape.cpp Shape.h
	g++ $(CCFLAGS) -c Shape.cpp

Triangle.o: Triangle.cpp Triangle.h
	g++ $(CCFLAGS) -c Triangle.cpp
         
# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign9
