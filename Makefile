# Replace icc (intel compiler) with the compiler used in your system.
# Put appropriate compiler options in CFLAGS.
CC=icc
CFLAGS=-std=c++11 -Ofast -w

OBJ_DIR=obj
OBJ=$(OBJ_DIR)/model_basic.o\
    $(OBJ_DIR)/model.o\

TARGET=libidea

.PHONY : all clean test

all : mkobj $(TARGET)

mkobj :
	-mkdir $(OBJ_DIR)
	-mkdir library

test : all
	$(CC) -c main_example.cpp -o $(OBJ_DIR)/main_example.o -I./include
	$(CC) -o test $(OBJ_DIR)/main_example.o -L./library -lidea

$(TARGET) : $(OBJ)
	ar rscv library/$(TARGET).a $(OBJ)

$(OBJ_DIR)/%.o : src/%.cpp
	$(CC) -c $< -o $@ $(CFLAGS) -I./src -I./include

clean :
	-rm $(OBJ_DIR)/*.o
	-rmdir $(OBJ_DIR)
	-rm library/$(TARGET).a
	-rmdir library
	-rm test
