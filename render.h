#pragma once

#include "game.h"
#include <string>

const SDL_Color GRID_COLOR     = { 255, 255, 255};
const SDL_Color PLAYER_X_COLOR = {   0, 153,   0};
const SDL_Color PLAYER_O_COLOR = {   0,   0, 255};
const SDL_Color TIE_COLOR      = { 153,   0, 153};


void renderGrid( SDL_Renderer * renderer, const SDL_Color * color)
{
	SDL_SetRenderDrawColor(renderer, color->r, color->g, color->b, 255);

	for (int i = 0; i < ROW_SIZE ; ++i)
	{
		// render the vertical lines across the whole window
		SDL_RenderDrawLine(renderer,
				   i * CELL_WIDTH, 0,
				   i * CELL_WIDTH, SCREEN_HEIGHT);

		// render the horizontal lines across the whole window
		SDL_RenderDrawLine(renderer,
				   0, i * CELL_HEIGHT,
				   SCREEN_WIDTH, i * CELL_HEIGHT);

	}
}


void renderX(SDL_Renderer * renderer,
	     int row, int column,
	     const SDL_Color * color)
{
}


void renderO(SDL_Renderer * renderer,
		int row, int column,
		const SDL_Color * color)
{
}


void renderBoard( SDL_Renderer * renderer, const int * board,	
	          const SDL_Color * player_x_color, const SDL_Color * player_o_color)
{
	for(int i = 0; i < ROW_SIZE; ++i)
	{
		for (int j = 0; j < ROW_SIZE; ++j)
		{
			switch (board[i * ROW_SIZE + j]) 
			{
				case PLAYER_X:
					renderX(renderer, i, j, player_x_color);
					break;
				case PLAYER_O:
					renderO(renderer, i, j, player_o_color);
					break;
				default: 
					break;
			}
		}

	}

}


void renderRunningState(SDL_Renderer * renderer, const Game * game)
{
	renderGrid(renderer, &GRID_COLOR);
}


void renderGameOver(SDL_Renderer * renderer, const Game * game, const SDL_Color * color)
{
	renderGrid(renderer, color);
}


void renderGame ( SDL_Renderer * renderer, const Game * game )
{
	switch (game->state)
	{
		case RUNNING:
			renderRunningState(renderer, game);
			break;

		case PLAYER_X_WON:
			renderGameOver(renderer, game, &PLAYER_X_COLOR);
			break;

		case PLAYER_O_WON:
			renderGameOver(renderer, game, &PLAYER_O_COLOR);
			break;

		case TIE:
			renderGameOver(renderer, game, &TIE_COLOR);
			break;

		case QUIT_GAME:
			break;
		default: 
			fprintf(stderr, "Something broke!");

	}
}

