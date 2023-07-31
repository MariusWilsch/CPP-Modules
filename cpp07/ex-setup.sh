#!/bin/bash

echo "Enter directory name:"
read dirname

if [ -d "$dirname" ]; then
    echo "Directory already exists!"
    exit 1
fi

mkdir "$dirname"
mkdir "$dirname/src"
mkdir "$dirname/inc"

echo "Enter filenames to add to src (space-separated):"
read -r src_files

for file in $src_files; do
    touch "$dirname/src/$file.cpp"
done

echo "Enter filenames to add to inc (space-separated):"
read -r inc_files

for file in $inc_files; do
    touch "$dirname/inc/$file.hpp"
done

touch "$dirname/Makefile"

cat > $dirname/Makefile <<EOF
CXX := clang++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
INC := -Iinc/

TARGET := executable

SRC_DIR := src/
OBJ_DIR := obj/

SRC := \$(wildcard \$(SRC_DIR)*.cpp)
OBJ := \$(patsubst \$(SRC_DIR)%.cpp,\$(OBJ_DIR)%.o,\$(SRC))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: \$(TARGET)

\$(TARGET): \$(OBJ)
	@\$(CXX) \$(CXXFLAGS)  \$^ -o \$@
	@echo "\$(GREEN)Executable created.\$(RESET)"

\$(OBJ_DIR)%.o: \$(SRC_DIR)%.cpp inc/*.hpp 
	@mkdir -p \$(dir \$@)
	@\$(CXX) \$(CXXFLAGS) \$(INC) -c \$< -o \$@

clean:
	@rm -rf \$(OBJ_DIR)
	@echo "\$(RED)Object files removed.\$(RESET)"

fclean: clean
	@rm -f \$(TARGET)
	@echo "\$(RED)Executable removed.\$(RESET)"

re: fclean all
EOF

echo "Directories and Makefile created successfully in $dirname."
