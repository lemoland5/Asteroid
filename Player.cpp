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
    SDLGameObject::update();

    if(m_UpdateCounter%m_ParticleDelay == 0){
        Game::getInstance()->addGameObject<Particle>(new LoaderParams(m_Position, 20, 20, 0, "particle"));
    }

}

void Player::handleEvents() {
//    std::cout<<m_Angle<<"\n";
    if(EventHandler::getInstance()->isMouseButtonDown(LEFT) || EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_LEFT)) m_Angle -= 4.0f;
    if(EventHandler::getInstance()->isMouseButtonDown(RIGHT) || EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_RIGHT)) m_Angle += 4.0f;

//    std::cout<<EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_W)<<"\n";
}

Player::Player(const LoaderParams *params) : SDLGameObject(params) {
    m_ParticleDelay = 4;
    m_UpdateCounter = 0;
    m_Speed = 2.0f;
}
