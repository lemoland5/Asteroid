#include "Game.h"
#include <iostream>
#include <SDL.h>

const int TARGET_FPS = 60;
const int TARGET_FRAMETIME = 1000/TARGET_FPS;
int frameStart, frameTime;

int main(int argc, char* argv[]) {
    if(Game::getInstance()->init("Asteroid", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,640, 480, SDL_WINDOW_SHOWN)){
        while(Game::getInstance()->isRunning()){
            frameStart = SDL_GetTicks64();
            Game::getInstance()->handleEvents();
            Game::getInstance()->update();
            Game::getInstance()->render();
            frameTime = SDL_GetTicks64() - frameStart;

            if(frameTime < TARGET_FRAMETIME){
                SDL_Delay(TARGET_FRAMETIME - frameTime);
            }

        }
        Game::getInstance()->clean();
    }
    return 0;
}
