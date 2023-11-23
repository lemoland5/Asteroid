#include "Particle.h"
#include "TextureManager.h"

void Particle::clean() {
    SDLGameObject::clean();
}

void Particle::update() {
    m_Width *= 0.95f;
    m_Height *= 0.95;

    SDLGameObject::update();
    m_Spin += 2.5f;

    if(m_Width <= 0 || m_Height <= 0) clean();
}

Particle::Particle(const LoaderParams* params): SDLGameObject(params){
    m_Spin *= (float)(rand()%6) - 2.5f;
}

void Particle::draw() {
    SDLGameObject::draw();
}