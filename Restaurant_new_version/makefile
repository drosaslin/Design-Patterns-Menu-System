.PHONY: directories clean
CC=g++
CFLAGS=-std=c++11
LIBS=-lgtest -lpthread
OBJ=obj
BIN=bin
SRC=src
TEST=test

all: directories $(BIN)/ut_all

$(BIN)/ut_all: $(OBJ)/ut_main.o
	$(CC) $(CFLAGS) -o $@ $(OBJ)/ut_main.o $(LIBS)
$(OBJ)/ut_main.o: $(TEST)/ut_main.cpp $(TEST)/ut_fs.h $(TEST)/ut_menuiterator.h $(SRC)/iterator.h $(SRC)/manager.h $(SRC)/product.h $(SRC)/item.h $(SRC)/ingredient.h $(SRC)/full_menu.h $(SRC)/restaurant_system.h $(SRC)/menu.h $(SRC)/manager.cpp $(SRC)/restaurant_system.h $(SRC)/main.cpp $(SRC)/category.h $(SRC)/customer.h $(SRC)/visitor.h $(SRC)/sort_by_price_visitor.h $(SRC)/sort_by_calorie_visitor.h
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p bin obj

clean:
	rm -rf $(OBJ) $(BIN)

stat:
	wc $(SRC)/* $(TEST)/*
