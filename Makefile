# Directories
ROOT_DIR := .
SRC_DIR := $(ROOT_DIR)/src
BUILD_DIR := $(ROOT_DIR)/build
HEADER_DIR := $(SRC_DIR)/headers
SOURCE_DIR := $(SRC_DIR)/impl

# Flags
GXXCOMP := g++
GXXF := -std=c++2a -pthread
WFLAGS := -Wall -Werror -m32
WNO_FLAGS := -Wno-unused-variable -Wno-unused-function -Wno-unknown-pragmas

# Commands
GXX := $(GXXCOMP) $(GXXF) $(WFLAGS) $(WNO_FLAGS)
GXXG := $(GXX) -g

# Main
MAIN_FILE := $(SRC_DIR)/main.cpp
EXE_NAME := main.exe

# Files
HEADER_FILES = $(wildcard $(HEADER_DIR)/*.hpp)
SOURCE_FILES = $(wildcard $(SOURCE_DIR)/*.cpp)
REQUIRED_FILES = $(MAIN_FILE) $(HEADER_FILES) $(SOURCE_FILES)

# Calls
Build: All
	mv $(EXE_NAME) $(BUILD_DIR)/

All: $(REQUIRED_FILES)
	$(GXX) -c $(MAIN_FILE) -o CompiledFile.o
	$(GXX) $(SOURCE_FILES) CompiledFile.o -o $(EXE_NAME)
	rm CompiledFile.o

DEBUG: $(REQUIRED_FILES)
	$(GXXG) -c $(MAIN_FILE) -o CompiledFile.o
	$(GXXG) $(SOURCE_FILES) CompiledFile.o -o $(EXE_NAME)
	rm CompiledFile.o

Clean: $(BUILD_DIR)/$(EXE_NAME)
	rm $^

