
#include <SDL2/SDL.h> 
#include <SDL2/SDL_image.h> 
#include <SDL2/SDL_timer.h>
#include "game.h"
#include "logic.h"
#include "render.h"


int main(int argc, char *argv[]) 
{
    if ( SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Couldn't initialize SDL: %s\n", SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow("Tic Tac Toe",
		    			   SDL_WINDOWPOS_CENTERED,
					   SDL_WINDOWPOS_CENTERED,
					   SCREEN_WIDTH,
                                           SCREEN_HEIGHT,
                                           SDL_WINDOW_SHOWN
		    			 );

    if ( window == NULL )
    {
	   fprintf(stderr, "SDL window error: %s\n", SDL_GetError() );
	   return EXIT_FAILURE;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1 , SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if ( renderer == NULL )
    {
	   SDL_DestroyWindow(window);
	   fprintf(stderr, "SDL window error: %s\n", SDL_GetError() );
	   return EXIT_FAILURE;
    }

    // creating the event object
    SDL_Event e;
    // initialize the game with empty grid
    Game game = {
    	{
	    	EMPTY, EMPTY, PLAYER_O,
    		EMPTY, PLAYER_X, EMPTY,
    		EMPTY, EMPTY, EMPTY
    	},
	PLAYER_X,
	RUNNING
    };

  
    while( game.state != QUIT_GAME )
    {
	    while( SDL_PollEvent(&e) )
   	    {
		    switch(e.type)
		    {
			    case SDL_QUIT:
				    game.state = QUIT_GAME;
				    break;

			    case SDL_MOUSEBUTTONDOWN:
				   clickOnField(&game,
						   e.button.y / CELL_HEIGHT,
						   e.button.x / CELL_WIDTH); 
				    break;

		            default: break;
		    }
	    }

	    // set the drawing color
	    SDL_SetRenderDrawColor(renderer, 0,0,0,255);
            // clear with the drawing color
	    SDL_RenderClear(renderer);
	    // render game
	    renderGame(renderer, &game);
	    // update the screen
	    SDL_RenderPresent(renderer);
    }

    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
