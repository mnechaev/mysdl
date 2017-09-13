S_DIR=src
B_DIR=build

S_FILES=$(S_DIR)/main.cpp
EXEC=$(B_DIR)/mysdl

CC=g++
CC_SDL=-lSDL

all:Build
Build:
$(CC) $(S_FILES)
build_run:
clean:
