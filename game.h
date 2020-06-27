#pragma once

// SDL constants
const unsigned int SCREEN_WIDTH = 640;
const unsigned int SCREEN_HEIGHT = 480;

// the grid row and column size
const unsigned int GRID_SIZE	= 3;

// cell hight and width constants
const float cellHight = SCREEN_HEIGHT / GRID_SIZE;
const float cellWidth = SCREEN_WIDTH / GRID_SIZE;


// game states
const unsigned int RUNNING 	= 0;
const unsigned int PLAYER_X_WON = 1;
const unsigned int PLAYER_O_WON = 2;
const unsigned int TIE		= 3;
const unsigned int QUIT_GAME 	= 4;

// filed state
const unsigned int EMPTY	= 0;
const unsigned int PLAYER_X	= 1;
const unsigned int PLAYER_O 	= 2;

// the main game struct
typedef struct 
{
	int grid[GRID_SIZE * GRID_SIZE];
	int field_state;
	int state;
} Game;

