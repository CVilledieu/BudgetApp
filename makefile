# Compiles project to a statically linked library
CC = gcc

LDflags = -L./libs -lglfw3 -lopengl32 -lgdi32 -luser32
CFLAGS = -Wall -I./include



APP = GUI


all: $(APP)

$(APP): src/main.c src/window.c src/glad.c
	$(CC) $(CFLAGS) -o $(APP) src/main.c src/window.c src/glad.c $(LDflags)