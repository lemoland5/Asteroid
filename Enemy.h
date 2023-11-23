#pragma once

#include "SDLGameObject.h"

class Enemy: public SDLGameObject{
public:
    void draw();
    void update();
    void handleCollisions();
    void clean();

    Enemy(const LoaderParams* params);
};
