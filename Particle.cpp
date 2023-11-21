#include "Particle.h"
#include "TextureManager.h"

void Particle::clean() {
    SDL_DestroyTexture(m_pTextureBuffer);
    delete this;
}

void Particle::update() {

        m_Alpha--;
        SDL_SetTextureAlphaMod(m_pTextureBuffer, m_Alpha);


}

Particle::Particle(const LoaderParams* params): SDLGameObject(params){
    m_Alpha = 255;
    m_pTextureBuffer = TextureManager::getInstance()->getTexture(m_TextureId);
}

void Particle::draw() {
    SDLGameObject::draw();
}
