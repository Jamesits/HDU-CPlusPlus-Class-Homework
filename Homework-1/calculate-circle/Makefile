SRC = calccir.cpp
PROGRAM = ./calccir
OBJ = $(SRC:.c=.o)
CC = g++
CFLAGS = -Os -std=c++11 -Wall -Wno-invalid-source-encoding
LINKPARAM = -std=c++11


: $(PROGRAM)

$(PROGRAM): $(OBJ)
	@echo "> Linking $(OBJ)..."
	@$(CC) -o $(PROGRAM) $(LINKPARAM) $(OBJ)

%.o: %.cpp
	@echo "> Compiling $<..."
	@$(CC) $(INCLUDE) $(CFLAGS) -c -o $@ $<
