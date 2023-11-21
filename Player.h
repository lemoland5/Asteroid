#pragma once

#include "SDLGameObject.h"

class Player: public SDLGameObject{
public:
    void draw();
    void drawEx();
    void update();
    void handleEvents();


    Player(const LoaderParams* params);

private:
    int m_ParticleDelay;
    int m_UpdateCounter;
};


