/*
 * screen.h
 *
 *  Created on: Jul 8, 2020
 *      Author: Andrew
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <iostream>
#include <SDL.h>

namespace pfs {

class screen {
public:
    /* window size constants*/
    static const int SCREEN_WIDTH = 800;
    static const int SCREEN_HEIGHT = 600;

private:
    SDL_Window* mainWindow;
    SDL_Renderer * windowRender;
    SDL_Texture* windowTexture;
    Uint32* buffer;
    int id;
    static int count;


public:
    /* cons/dest */
    screen();
    ~screen();

    /* methods */
    bool init();
    void update();
    bool setPixelRGBA(int x,int y, Uint32 RGBA);
    bool setPixelRGBA(int x,int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha);
    bool processEvents();
    void close();

};

} /* namespace pfs */

#endif /* SCREEN_H_ */
