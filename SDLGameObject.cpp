#include "Game.h"
#include "SDLGameObject.h"
#include "TextureManager.h"
#include <iostream>

SDLGameObject::SDLGameObject(const LoaderParams* params): GameObject(){
    m_Position = params->m_Position;
    m_Width = params->m_Width;
    m_Height = params->m_Height;
    m_Spin = params->m_Spin;

    m_Angle = params->m_Angle;
    m_Speed = params->m_Speed;
    m_Velocity = params->m_Velocity;
    m_Acceleration = params->m_Acceleration;

    m_MarkedForDeletion = params->m_MarkedForDeletion;

    m_TextureId = params->m_TextureId;
}

void SDLGameObject::draw() {
    TextureManager::getInstance()->drawFrameEx(m_TextureId,0,0,512,512, (int)m_Position.x, (int)m_Position.y,m_Width,m_Height,m_Spin);
}

void SDLGameObject::update() {
        // Basic position update
    m_Velocity = degToVector(m_Angle) * m_Speed;
    m_Position += m_Velocity;

    for(size_t i = 0; i < Game::getInstance()->getGameObjects().size(); i++){
        SDL_Rect firstRect, secondRect;
        firstRect.x = Game::getInstance()->getGameObjects()[i]->m_Position.x;
        firstRect.y = Game::getInstance()->getGameObjects()[i]->m_Position.y;
        firstRect.w = Game::getInstance()->getGameObjects()[i]->m_Width;
        firstRect.h = Game::getInstance()->getGameObjects()[i]->m_Height;

        secondRect.x = m_Position.x;
        secondRect.y = m_Position.y;
        secondRect.w = m_Width;
        secondRect.h = m_Height;

        if(SDL_HasIntersection(&firstRect, &secondRect) == SDL_TRUE) m_CollisionStack.push(Game::getInstance()->getGameObjects()[i]);
    }
//    std::cout << m_Position.x<<", "<<m_Position.y<<"\n";
}

void SDLGameObject::clean() {
        // Clean collisions
    while(!m_CollisionStack.empty()){
        m_CollisionStack.pop();
    }

    m_MarkedForDeletion = true;
}
