#pragma once

#include "SDLGameObject.h"
#include <SDL.h>

class Particle: public SDLGameObject{
public:
    Particle(const LoaderParams* params);
    void update();
    void draw();
    void clean();


private:

};