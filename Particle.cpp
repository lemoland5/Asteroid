#include "Game.h"
#include "Particle.h"
#include "TextureManager.h"

void Particle::clean() {
    SDLGameObject::clean();
}

void Particle::update() {


    SDLGameObject::update();
    handleCollisions();

    m_Width -= 1.0f;
    m_Height -= 0.1f;
    m_Spin += 2.5f;


    if(m_Width <= 0 || m_Height <= 0) clean();
}

void Particle::handleCollisions() {
//    if(m_CollisionStack.top() != Game::getInstance()->getPlayer()) clean();
}

Particle::Particle(const LoaderParams* params): SDLGameObject(params){
    m_Spin *= (float)(rand()%6) - 2.5f;
    m_IsPlayerDamage = false;
    m_IsEnemyDamage = true;
}

void Particle::draw() {
    SDLGameObject::draw();
}