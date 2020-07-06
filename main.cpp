/*
 * main.cpp
 *
 *  Created on: Jul 5, 2020
 *      Author: Andrew
 */

#include <iostream>
#include <SDL.h>

using namespace std;

int main() {
	/* window size constants*/
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HIGHT = 600;

	/* local variables */
	SDL_Event event;
	bool gameLoop = true;
	SDL_Window* mainWindow = NULL;
    SDL_Renderer * windowRender = NULL;
    SDL_Texture* windowTexture = NULL;
    Uint32* buffer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init Failed!" << endl;
		SDL_Quit();
		return 1;
	}
	cout << "SDL Init Successful!" << endl;

	/* create window */
	mainWindow = SDL_CreateWindow("Particle Fire Explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_HIGHT,SDL_WINDOW_SHOWN);

	if ( NULL == mainWindow) {
		cout << "Failed to create Window Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}

    /* create a renderer */
	windowRender = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);

	if (NULL == windowRender) {
		cout << "Failed to create Window Render: " << SDL_GetError() << endl;
		SDL_DestroyWindow(mainWindow);
		SDL_Quit();
		return 1;
	}


	windowTexture = SDL_CreateTexture(windowRender, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HIGHT);
	if (NULL == windowTexture) {
		cout << "Failed to create Window Texture: " << SDL_GetError() << endl;
		SDL_DestroyRenderer(windowRender);
		SDL_DestroyWindow(mainWindow);
		SDL_Quit();
		return 1;
	}
	buffer = new Uint32[SCREEN_WIDTH*SCREEN_HIGHT];

	memset(buffer,0xFF,SCREEN_WIDTH*SCREEN_HIGHT*sizeof(Uint32));

	SDL_UpdateTexture(windowTexture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(windowRender);
	SDL_RenderCopy(windowRender, windowTexture, NULL, NULL);
	SDL_RenderPresent(windowRender);


	while(true == gameLoop){


		/* Capture Events*/
		if( SDL_WaitEvent(&event) ){
			if((event.type == SDL_QUIT)){
			gameLoop = false;
			} else {
				cout<< "Another Event " << event.type << endl;
			}
		}
	}

	delete []buffer;
    SDL_DestroyTexture(windowTexture);
    SDL_DestroyRenderer(windowRender);
    SDL_DestroyWindow(mainWindow);
	SDL_Quit();
	cout << "SDL Quit Successful!" << endl;
	return 0;
}
