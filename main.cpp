#include "Game.h"
#include <iostream>
#include <SDL.h>

int main() {
    if(Game::getInstance()->init("Asteroid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640, 480, SDL_WINDOW_SHOWN)){
        while(Game::getInstance()->isRunning()){
            Game::getInstance()->handleEvents();
            Game::getInstance()->update();
            Game::getInstance()->render();
        }
        Game::getInstance()->clean();
    }
    return 0;
}
