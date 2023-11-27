#include "Enemy.h"
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
        m_WindowHeight = h;
        m_WindowWidth = w;

        if(m_pWindow){
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if(m_pRenderer){
                SDL_SetRenderDrawColor(m_pRenderer, 34, 34, 51, 255);

                TextureManager::getInstance()->load("../assets/rocketship1.png", "rocket");
                TextureManager::getInstance()->load("../assets/rocketship.png", "rocketbad");

//                SDL_SetTextureAlphaMod(TextureManager::getInstance()->getTexture("rocket"),50);
                TextureManager::getInstance()->load("../assets/star.png", "particle");

//                float degrees = 0.0f;
//                std::cout<<degToVector(degrees).x<<", "<<degToVector(degrees).y<<"\n";



                    // DO NOT EDIT PLACEMENT OF THIS LINE
                addGameObject<Player>(new LoaderParams({300,200},40,40,80.0f,"rocket",0.0f,0,{},{},{})) ;

                addGameObject<Enemy>(new LoaderParams({600,400},40,40,80.0f,"rocketbad",0.0f,0,{},{},{}, {})) ;

                m_Running = true;
                m_GameTicks = 0;

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

    ++m_GameTicks;
//    std::cout<<getVectorAngle({0,1}, {1,0})<<"\n";

    if(m_GameTicks % 180 == 0){
        addGameObject<Enemy>(new LoaderParams({static_cast<float>(m_WindowWidth * (rand()%100)/100),static_cast<float>(m_WindowHeight * (rand()%40)/100)},40,40,80.0f,"rocketbad",0.0f,1,{},{},{})) ;
    }



    for(int i = 0; i < m_GameObjects.size(); i++){

        m_GameObjects[i]->update();

        if(m_GameObjects[i]->isMarkedForDeletion()){
            m_GameObjects[i]->clean();
            delete m_GameObjects[i];
            m_GameObjects.erase(m_GameObjects.begin() + i);
        }
    }

    std::cout<<m_GameObjects.size()<<"\n";
}

void Game::clean(){
    SDL_DestroyRenderer(m_pRenderer);
    SDL_DestroyWindow(m_pWindow);
}

