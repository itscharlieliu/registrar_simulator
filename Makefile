BUILD_FLAGS = -W -Wall -pedantic
CC = g++
RM = rm
OUT = *.out

all: a.out

a.out: Makefile Input.cpp Main.cpp Simulation.cpp Student.cpp Window.cpp
	$(CC) $(BUILD_FLAGS) Input.cpp Main.cpp Simulation.cpp Student.cpp Window.cpp -o a.out

clean:
	$(RM) $(OUT)
