/*
 * screen.cpp
 *
 *  Created on: Jul 8, 2020
 *      Author: Andrew
 */

#include "screen.h"

namespace pfs {

int screen::count = 0;

screen::screen(): mainWindow(NULL), windowRender(NULL), windowTexture(NULL), buffer(NULL) {
    id = ++count;
}

screen::~screen(){
    count--;
}



bool screen::init(){

    /* Init SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL Init Failed!" << std::endl;
        return false;
    }

    /* create window */
    mainWindow = SDL_CreateWindow("Particle Fire Explosion",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);

    if (NULL == mainWindow) {
        std::cout << "Failed to create Window Error: " << SDL_GetError() << std::endl;
        return false;
    }

        /* create a renderer */
    windowRender = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_PRESENTVSYNC);

    if (NULL == windowRender) {
        std::cout << "Failed to create Window Render: " << SDL_GetError() << std::endl;
        return false;
    }

    /* create texture */
    windowTexture = SDL_CreateTexture(windowRender, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
    if (NULL == windowTexture) {
        std::cout << "Failed to create Window Texture: " << SDL_GetError() << std::endl;
        return false;
    }

    buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

    memset(buffer,0xFF,SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

    std::cout << "screen id "<< id << " Init Successful!" << std::endl;
    return true;
}

void screen::draw(){
    SDL_UpdateTexture(windowTexture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(windowRender);
    SDL_RenderCopy(windowRender, windowTexture, NULL, NULL);
    SDL_RenderPresent(windowRender);
}


bool screen::processEvents(){
    SDL_Event event;
    /* Capture Events*/
    if( SDL_WaitEvent(&event) ){
        if(event.type == SDL_QUIT){
        return false;
        } else {
            std::cout<< "Another Event " << event.type << std::endl;
        }
    }
    return true;
}

void screen::close(){

    delete []buffer;

    if (NULL != windowTexture){
        SDL_DestroyTexture(windowTexture);
    }

    if (NULL != windowRender) {
        SDL_DestroyRenderer(windowRender);
    }

    if (NULL != mainWindow) {
        SDL_DestroyWindow(mainWindow);
    }

    SDL_Quit();
    std::cout << "screen id "<< id << " Quit Successful!" << std::endl;
}

} /* namespace pfs */
