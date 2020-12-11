#
# PROGRAM:  assign2
# DATE DUE: 2/21/19
#

# Compiler variables
CCFLAGS = -Wall -std=c++11

# Rule to link object code files to create executable file
assign2: assign2.o Seller.o SellerList.o
	g++ $(CCFLAGS) -o assign2 assign2.o Seller.o SellerList.o

# Rules to compile source code files to object code
assign2.o: assign2.cpp SellerList.h
	g++ $(CCFLAGS) -c assign2.cpp

Seller.o: Seller.cpp Seller.h
	g++ $(CCFLAGS) -c Seller.cpp

SellerList.o: SellerList.cpp SellerList.h
	g++ $(CCFLAGS) -c SellerList.cpp

SellerList.h: Seller.h

# Pseudo-target to remove object code and executable files
clean:
	-rm *.o assign2
