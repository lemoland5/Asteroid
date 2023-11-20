#pragma once

#include "SDLGameObject.h"

class Player: public SDLGameObject{
public:
    void draw();
    void update();

    Player(const LoaderParams* params): SDLGameObject(params) {};
};


