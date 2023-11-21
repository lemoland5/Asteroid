#include "EventHandler.h"
#include "Player.h"
#include <iostream>

void Player::draw(){
    SDLGameObject::draw();
}

void Player::update() {
//    std::cout<<"Update player \n";
    handleEvents();
    SDLGameObject::update();
}

void Player::handleEvents() {
    std::cout<<m_Angle<<"\n";
    if(EventHandler::getInstance()->isMouseButtonDown(LEFT)) m_Angle -= 2.0f;
    if(EventHandler::getInstance()->isMouseButtonDown(RIGHT)) m_Angle += 2.0f;
}
