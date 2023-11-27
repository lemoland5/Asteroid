#include "Enemy.h"
#include "EventHandler.h"
#include "Game.h"
#include "Particle.h"
#include "TextureManager.h"
#include <iostream>

void Enemy::draw(){
    SDLGameObject::draw();
}

Enemy::Enemy(const LoaderParams *params) : SDLGameObject(params) {
    m_ParticleDelay = 4;
    m_UpdateCounter = 0;

    m_IsPlayerDamage = true;
    m_IsEnemyDamage = false;
}

void Enemy::update() {

    m_UpdateCounter++;
    m_Spin = m_Angle + 45.0f;

//    std::cout<<"Update player \n";
    SDLGameObject::update();
    handleCollisions();

        // -y because of reversed y-axis in sdl
    m_Angle = getVectorAngle({Game::getInstance()->getPlayer()->getPosition().x - m_Position.x,-Game::getInstance()->getPlayer()->getPosition().y - -m_Position.y}, {1,0});


//    if(m_UpdateCounter%m_ParticleDelay == 0){
//        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 50, m_Position.y + m_Width/2 - 50}, 100, 100, m_Angle-180.0f, "particle",m_Spin,m_Speed,{}, {}, {}));
//    }

}

void Enemy::handleCollisions() {
    if(m_CollisionStack.top()->isEnemyDamage()) clean();

}

void Enemy::clean() {
    SDLGameObject::clean();
}
