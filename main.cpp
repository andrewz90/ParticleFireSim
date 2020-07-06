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
	const int SCREEN_LENGTH = 600;

	/* local variables */
	bool gameLoop = true;
	SDL_Event event;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init Failed!" << endl;
		SDL_Quit();
		return 1;
	}
	cout << "SDL Init Successful!" << endl;

	SDL_Window* mainWindow = SDL_CreateWindow("Particle Fire Explosion",
	SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
			SCREEN_LENGTH,SDL_WINDOW_SHOWN);

	if ( NULL == mainWindow) {
		cout << "Failed to create Window Error: " << SDL_GetError() << endl;
		SDL_Quit();
		return 1;
	}


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

    SDL_DestroyWindow(mainWindow);
	SDL_Quit();
	cout << "SDL Quit Successful!" << endl;
	return 0;
}
