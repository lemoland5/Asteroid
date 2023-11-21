#include "Particle.h"
#include "TextureManager.h"

void Particle::clean() {
//    SDL_DestroyTexture(m_pTextureBuffer);
    m_MarkedForDeletion = true;
}

void Particle::update() {
//    SDL_SetTextureAlphaMod(m_pTextureBuffer, m_Alpha);

    --m_Width;
    --m_Height;

    m_Angle += 0.5f * spin;

    if(m_Width <= 0 || m_Height <= 0) clean();
//    SDLGameObject::update();
}

Particle::Particle(const LoaderParams* params): SDLGameObject(params){
    spin = rand() % 5 - 2;
}


void Particle::draw() {
    SDLGameObject::draw();
}