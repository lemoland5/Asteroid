#include "EventHandler.h"
#include "Game.h"
#include "Particle.h"
#include "Player.h"
#include "TextureManager.h"
#include <iostream>

void Player::draw(){
    SDLGameObject::draw();
}

void Player::update() {

    m_UpdateCounter++;
    m_Spin = m_Angle;

//    std::cout<<"Update player \n";
    handleEvents();
    updateMovement();
    updateAction();
    handleCollisions();



//    if(m_UpdateCounter%m_ParticleDelay == 0){
//        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 50, m_Position.y + m_Width/2 - 50}, 100, 100, m_Angle-180.0f, "particle",m_Spin,m_Speed,{}, {}, {}));
//    }

}

void Player::handleEvents() {
//    std::cout<<m_Angle<<"\n";
    if(EventHandler::getInstance()->isMouseButtonDown(LEFT) || EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_LEFT)) m_Angle -= 2.5f;
    if(EventHandler::getInstance()->isMouseButtonDown(RIGHT) || EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_RIGHT)) m_Angle += 2.5f;
    if(EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_SPACE)) shoot();

//    std::cout<<EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_W)<<"\n";
}

Player::Player(const LoaderParams *params) : SDLGameObject(params) {
    m_ParticleDelay = 4;
    m_UpdateCounter = 0;

    m_IsMoving = false;
    m_CanMove = true;
    m_CanShoot = true;

    m_IsPlayerDamage = false;
}

void Player::updateMovement() {

//    std::cout<<m_IsMoving<<" "<<m_CanShoot<<"\n";

        // IsMoving / CanShoot assignment
    SDLGameObject::update();
    if(m_Velocity.length()<=5) m_IsMoving = false;
    if(m_IsMoving) m_CanShoot = false;
    else m_CanShoot = true;

        // Slowdown
    if(m_Velocity.length()>0) m_Speed -= 0.05f;
    if(m_Speed < 0) m_Speed = 0;


}

void Player::updateAction() {
    if(m_IsMoving) m_CanShoot = false;

}

void Player::handleCollisions() {
    if(m_CollisionStack.top()->isPlayerDamage()) clean();
}

void Player::shoot() {

    if(m_CanShoot){
            // Initial pushback
        m_IsMoving = true;
        m_Speed = 12.0f;

            // Primary
        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 25, m_Position.y + m_Height/2 - 25}, 50, 40, m_Angle - 180.0f, "particle",m_Spin,m_Speed,{}, {}, {}));

            // Secondary
        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 15, m_Position.y + m_Height/2 - 15}, 30, 20, m_Angle - 175.0f, "particle",m_Spin,m_Speed*0.94f,{}, {}, {}));
        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 15, m_Position.y + m_Height/2 - 15}, 30, 20, m_Angle - 185.0f, "particle",m_Spin,m_Speed*0.89f,{}, {}, {}));

            // Tertiary
        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 10, m_Position.y + m_Height/2 - 10}, 20, 20, m_Angle - 170.0f, "particle",m_Spin,m_Speed*0.8f,{}, {}, {}));
        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 10, m_Position.y + m_Height/2 - 10}, 20, 20, m_Angle - 190.0f, "particle",m_Spin,m_Speed*0.81f,{}, {}, {}));


    }

}

void Player::clean() {
    SDLGameObject::clean();
}
