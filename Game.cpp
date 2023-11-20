#include "Game.h"
#include "TextureManager.h"
#include "Vector.h"
#include <iostream>
#include <SDL.h>

    // static
Game* Game::s_pInstance = nullptr;

    //static
Game* Game::getInstance(){
    if(!s_pInstance) s_pInstance = new Game();
    return s_pInstance;
}

Game::Game(){
    m_pWindow = nullptr;
    m_pRenderer = nullptr;

    m_Running  = false;
}

bool Game::init(const char *windowname, int x, int y, int w,    int h, SDL_WindowFlags flags) {
    if(!SDL_Init(SDL_INIT_EVERYTHING)){
        m_pWindow = SDL_CreateWindow(windowname, x, y, w, h, flags);

        if(m_pWindow){
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if(m_pRenderer){
                SDL_SetRenderDrawColor(m_pRenderer, 255, 0, 0, 255);

                TextureManager::getInstance()->load("../assets/rocketship.png", "rocket");



//                float degrees = 0.0f;
//                std::cout<<degToVector(degrees).x<<", "<<degToVector(degrees).y<<"\n";


                m_pPlayer = new Player(new LoaderParams({100,100},20,20,70.0f,"rocket"));




                m_Running = true;

                return true;
            }
        }
    }

    return false;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);

    m_pPlayer->draw();

    SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents() {
    SDL_Event event;
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT:
            m_Running = false;
            break;
    }
}

void Game::update() {
//    std::cout<<SDL_GetTicks64()<<"\n";
    m_pPlayer->update();
}

void Game::clean(){
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
}