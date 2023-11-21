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
//    std::cout<<"Update player \n";
    handleEvents();
    SDLGameObject::update();

    if(SDL_GetTicks64()%100 == 0) {

        Game::getInstance()->addGameObject<Particle>(new LoaderParams({300, 200}, 80, 80, 80.0f, "particle"));
    }
}

void Player::handleEvents() {
//    std::cout<<m_Angle<<"\n";
    if(EventHandler::getInstance()->isMouseButtonDown(LEFT) || EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_LEFT)) m_Angle -= 4.0f;
    if(EventHandler::getInstance()->isMouseButtonDown(RIGHT) || EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_RIGHT)) m_Angle += 4.0f;

//    std::cout<<EventHandler::getInstance()->isKeyboardKeyDown(SDL_SCANCODE_W)<<"\n";
}
