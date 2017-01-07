OBJS = main.cpp Vector2D.cpp Timer.cpp Game.cpp Object.cpp Plate.cpp Ball.cpp

CC = g++
COMPILER_FLAGS = -w -std=c++14 -Iinclude/

LINKER_FLAGS = -lSDL2 -lSDL2pp

OBJ_NAME = game.out

all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
