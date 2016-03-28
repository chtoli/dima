CC = g++
CXXFLAGS = -std=c++11 -c -Wall -I$(INC)
LFLAGS = -Wall

#PATH
INC = ./include
SRC = ./src
BIN = ./bin


all: main.o rational.o gcd_lcm.o is_unit_inv.o
	$(CC) $(LFLAGS) $(BIN)/is_unit_inv.o $(BIN)/gcd_lcm.o $(BIN)/rational.o $(BIN)/main.o  -o dima

main.o: main.cpp $(INC)/rational.h $(INC)/gcd_lcm.h $(INC)/is_unit_inv.h
	$(CC) $(CXXFLAGS) main.cpp -o $(BIN)/main.o

rational.o: $(SRC)/rational.cpp $(INC)/rational.h $(INC)/gcd_lcm.h
	$(CC) $(CXXFLAGS) $(SRC)/rational.cpp -o $(BIN)/rational.o
gcd_lcm.o: $(SRC)/gcd_lcm.cpp $(INC)/gcd_lcm.h
	$(CC) $(CXXFLAGS) $(SRC)/gcd_lcm.cpp -o $(BIN)/gcd_lcm.o

is_unit_inv.o: $(SRC)/is_unit_inv.cpp $(INC)/is_unit_inv.h $(INC)/rational.h
	$(CC) $(CXXFLAGS) $(SRC)/is_unit_inv.cpp -o $(BIN)/is_unit_inv.o
