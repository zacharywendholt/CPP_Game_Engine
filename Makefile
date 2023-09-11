CFLAGS  = -g -Wall
INCLUDES = -IC:/DEV/SDL2/include/SDL2 -IC:/DEV/SDL2_image/include/SDL2 -IC:/DEV/SDL2/include/headers -IC:/DEV/SDL2_image/include/headers
LIBINCLUDES = -LC:/DEV/SDL2/lib -LC:/DEV/SDL2_image/lib
INC = $(INCLUDES) $(LIBINCLUDES)
LIBS =  -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
SOURCE_FILES = src/utilities/point.cpp src/player.cpp src/main.cpp src/window.cpp src/sprite.cpp
all:
	g++ -Wall $(INC) -o Main $(SOURCE_FILES) $(LIBS)