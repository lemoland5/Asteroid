#include "SDLGameObject.h"
#include "TextureManager.h"
#include <iostream>

SDLGameObject::SDLGameObject(const LoaderParams* params): GameObject(){
    m_Position = params->m_Position;
    m_Angle = params->m_Angle;

    m_Width = params->m_Width;
    m_Height = params->m_Height;

    m_TextureId = params->m_TextureId;

    m_Speed = 6.0f;

    m_Velocity = {1,1};
    m_Acceleration = 0;
}

void SDLGameObject::draw() {
    TextureManager::getInstance()->drawFrameEx(m_TextureId,0,0,512,512, (int)m_Position.x, (int)m_Position.y,m_Width,m_Height,m_Angle+90);
}

void SDLGameObject::update() {
    m_Velocity = degToVector(m_Angle) * m_Speed;
    m_Position += m_Velocity;
//    std::cout << m_Position.x<<", "<<m_Position.y<<"\n";
}