main:
	clang --std=c++17 -g -Wall -pedantic main.cpp -o tic-tac-toe `sdl2-config --cflags --libs` -lSDL2_image
clean:
	rm tic-tac-toe
