#pragma once

#include "SDLGameObject.h"

class Player: public SDLGameObject{
public:
    void draw();
    void update();
    void handleEvents();
    void handleCollisions();
    void shoot();

    void clean();

    void updateMovement();
    void updateAction();


    Player(const LoaderParams* params);

};


