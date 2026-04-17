SRC_DIR = ./src
OBJ_DIR = ./build/obj
BIN_DIR = ./build/bin
INC_DIR = ./inc
DOC_DIR = ./build/doc

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))
BIN_FILES = $(BIN_DIR)

all: $(OBJ_FILES)
	mkdir -p $(BIN_DIR)
	gcc -o $(BIN_DIR)/a.exe $(OBJ_FILES)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	gcc -c $< -o $@ -I $(INC_DIR)

doc: $(SRC_FILES)
	mkdir -p $(DOC_DIR)
	doxygen Doxyfile