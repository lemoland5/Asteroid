#include "SDLGameObject.h"
#include "TextureManager.h"
#include <iostream>

SDLGameObject::SDLGameObject(const LoaderParams* params): GameObject(){
    m_Position = params->m_Position;
    m_Angle = params->m_Angle;

    m_Width = params->m_Width;
    m_Height = params->m_Height;

    m_TextureId = params->m_TextureId;

    m_Speed = 3.50f;

    m_Velocity = {1,1};
    m_Acceleration = 0;
}

void SDLGameObject::draw() {
    TextureManager::getInstance()->draw(m_TextureId, (int)m_Position.x, (int)m_Position.y,m_Width,m_Height);
}

void SDLGameObject::update() {
    m_Velocity = degToVector(m_Angle) * m_Speed;
    m_Position += m_Velocity;
//    std::cout << m_Position.x<<", "<<m_Position.y<<"\n";
}