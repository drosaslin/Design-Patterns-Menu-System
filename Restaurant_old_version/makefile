<<<<<<< HEAD:makefile
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
$(OBJ)/ut_main.o: $(TEST)/ut_main.cpp $(TEST)/ut_fs.h $(TEST)/ut_menuiterator.h $(SRC)/base_menu.h $(SRC)/menu_item.h $(SRC)/iterator.h $(SRC)/manager.h $(SRC)/manager.cpp $(SRC)/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p bin obj

clean:
	rm -rf $(OBJ) $(BIN)

stat:
	wc $(SRC)/* $(TEST)/*
=======
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
$(OBJ)/ut_main.o: $(TEST)/ut_main.cpp $(TEST)/ut_fs.h $(TEST)/ut_menuiterator.h $(SRC)/base_menu.h $(SRC)/menu_item.h $(SRC)/iterator.h $(SRC)/manager.h $(SRC)/manager.cpp $(SRC)/main.cpp
	$(CC) $(CFLAGS) -c $< -o $@

directories:
	mkdir -p bin obj

clean:
	rm -rf $(OBJ) $(BIN)

stat:
	wc $(SRC)/* $(TEST)/*
>>>>>>> 396b6d4bd3f9d070e4c4927349a2626ad3d6bc76:Restaurant_old_version/makefile
