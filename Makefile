INCLUDE_DIR = ./include
CONFIG_DIR = ./src
OBJ_DIR = ./obj
BIN_DIR = ./bin
SRC_DIR = ./src
SRC_SUBDIRS = $(shell find $(SRC_DIR)/* -type d | cut -d/ -f3)

CC = gcc
FLAGS := -Wall -g -std=c99

SRCS = $(shell find $(SRC_DIR) -name "*.c")
OBJS = $(patsubst %.c,%.o, $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS)))

BIN_NAME = cmacs

.PHONY: clean directories run

.DEFAULT_GOAL: buildandrun
buildandrun: build run

build: directories cmacs 

cmacs: $(OBJS)
	gcc -o $(addprefix $(BIN_DIR)/, $(BIN_NAME)) -lncurses $(OBJS)

# invent a better make system that works dynamically... maybe with an external script that generates another makefile
obj/%.o: src/%.c
	$(CC) -o $@ -c -I$(INCLUDE_DIR) -I$(CONFIG_DIR) $(FLAGS) $<
obj/core/%.o: src/core/%.c
	$(CC) -o $@ -c -I$(INCLUDE_DIR) -I$(CONFIG_DIR) $(FLAGS) $<
obj/logger/%.o: src/logger/%.c
	$(CC) -o $@ -c -I$(INCLUDE_DIR) -I$(CONFIG_DIR) $(FLAGS) $<
obj/lua/%.o: src/lua/%.c
	$(CC) -o $@ -c -I$(INCLUDE_DIR) -I$(CONFIG_DIR) $(FLAGS) $<
obj/modulemanager/%.o: src/modulemanager/%.c
	$(CC) -o $@ -c -I$(INCLUDE_DIR) -I$(CONFIG_DIR) $(FLAGS) $<
obj/visual/%.o: src/visual/%.c
	$(CC) -o $@ -c -I$(INCLUDE_DIR) -I$(CONFIG_DIR) $(FLAGS) $<

directories:
	@mkdir -vp $(BIN_DIR) 
	@mkdir -vp $(addprefix $(OBJ_DIR)/,$(SRC_SUBDIRS))

run:
	bin/cmacs

clean:
	rm -r ./bin
	rm -r ./obj
