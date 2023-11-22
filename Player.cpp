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
//    std::cout<<"Update player \n";
    handleEvents();
    updateMovement();
    updateAction();

    m_Spin = m_Angle;


//    if(m_UpdateCounter%m_ParticleDelay == 0){
//        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 50, m_Position.y + m_Width/2 - 50}, 100, 100, m_Angle-180.0f, "particle",m_Spin,m_Speed,{}, {}, {}));
//    }

}

void Player::handleEvents() {
//    std::cout<<m_Angle<<"\n";
    if(EventHandler::getInstance()->isMouseButtonDown(LEFT) || EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_LEFT)) m_Angle -= 1.5f;
    if(EventHandler::getInstance()->isMouseButtonDown(RIGHT) || EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_RIGHT)) m_Angle += 1.5f;
    if(EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_SPACE)) shoot();

//    std::cout<<EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_W)<<"\n";
}

Player::Player(const LoaderParams *params) : SDLGameObject(params) {
    m_ParticleDelay = 4;
    m_UpdateCounter = 0;

    m_IsMoving = false;
    m_CanMove = true;
    m_CanShoot = true;
}

void Player::updateMovement() {

    std::cout<<m_IsMoving<<" "<<m_CanShoot<<"\n";

    SDLGameObject::update();
    if(m_Velocity.length()<=0) m_IsMoving = false;
    if(m_IsMoving) m_CanShoot = false;
    else m_CanShoot = true;


    if(m_IsMoving && m_Speed > 0) m_Speed -= 0.05f;
    if(m_Speed < 0) m_Speed = 0;

    if(m_Position.x > Game::getInstance()->getWindowWidth() + 1) m_Position.x = 1 - m_Width;
    if(m_Position.x < 1 - m_Width) m_Position.x = Game::getInstance()->getWindowWidth();

    if(m_Position.y > Game::getInstance()->getWindowHeight() + 1) m_Position.y = 1 - m_Height;
    if(m_Position.y < 1 - m_Height) m_Position.y = Game::getInstance()->getWindowHeight();



}

void Player::updateAction() {
    if(m_IsMoving) m_CanShoot = false;

}

void Player::shoot() {

    if(m_CanShoot){
        m_IsMoving = true;
        m_Speed = 12.0f;
        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 25, m_Position.y + m_Height/2 - 25}, 50, 40, m_Angle - 180.0f, "particle",m_Spin,m_Speed,{}, {}, {}));

        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 15, m_Position.y + m_Height/2 - 15}, 30, 20, m_Angle - 175.0f, "particle",m_Spin,m_Speed*0.94f,{}, {}, {}));
        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 15, m_Position.y + m_Height/2 - 15}, 30, 20, m_Angle - 185.0f, "particle",m_Spin,m_Speed*0.89f,{}, {}, {}));


        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 10, m_Position.y + m_Height/2 - 10}, 20, 20, m_Angle - 170.0f, "particle",m_Spin,m_Speed*0.8f,{}, {}, {}));
        Game::getInstance()->addGameObject<Particle>(new LoaderParams({m_Position.x + m_Width/2 - 10, m_Position.y + m_Height/2 - 10}, 20, 20, m_Angle - 190.0f, "particle",m_Spin,m_Speed*0.81f,{}, {}, {}));


    }

}
