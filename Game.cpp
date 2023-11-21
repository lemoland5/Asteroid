#include "EventHandler.h"
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
                SDL_SetRenderDrawColor(m_pRenderer, 80, 0, 150, 255);

                TextureManager::getInstance()->load("../assets/rocketship1.png", "rocket");
//                SDL_SetTextureAlphaMod(TextureManager::getInstance()->getTexture("rocket"),50);
                TextureManager::getInstance()->load("../assets/particle.jpg", "particle");

//                float degrees = 0.0f;
//                std::cout<<degToVector(degrees).x<<", "<<degToVector(degrees).y<<"\n";


                addGameObject<Player>(new LoaderParams({300,200},80,80,80.0f,"rocket")) ;




                m_Running = true;

                return true;
            }
        }
    }

    return false;
}

void Game::render() {
    SDL_RenderClear(m_pRenderer);

    for(auto & m_GameObject : m_GameObjects){
        m_GameObject->draw();
    }

    SDL_RenderPresent(m_pRenderer);
}

void Game::handleEvents() {
    EventHandler::getInstance()->update();
    if(EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_ESCAPE)) m_Running = false;
}
void Game::update() {
//    std::cout<<SDL_GetTicks64()<<"\n";

    for(auto & m_GameObject : m_GameObjects){
        m_GameObject->update();
    }

    std::cout<<m_GameObjects.size()<<"\n";
}

void Game::clean(){
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
}

