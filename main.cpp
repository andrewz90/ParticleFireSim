/*
 * main.cpp
 *
 *  Created on: Jul 5, 2020
 *      Author: Andrew
 */


#include "screen.h"

int main() {
    bool gameLoop = true;
    pfs::screen mainScreen;

    mainScreen.init();
    mainScreen.draw();
    while(true == gameLoop){
        gameLoop = mainScreen.processEvents();
    }
    mainScreen.close();
    return 0;
}
