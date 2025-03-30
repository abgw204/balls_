CC = g++
CFLAGS = -Lraylib -lraylib -lm -lpthread -ldl -lX11 -Iinclude -Wall
SRC_DIR = src
OBJ_DIR = obj
EXEC = Cub2d

SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(CFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CC) -c $< -o $@ $(CFLAGS)

re: clean all

clean:
	rm -rf $(OBJ_DIR) $(EXEC)