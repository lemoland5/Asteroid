#include "Game.h"
#include "TextureManager.h"
#include <SDL_image.h>

    // static
TextureManager* TextureManager::s_pInstance = nullptr;

    // static
TextureManager* TextureManager::getInstance() {
    if(!s_pInstance)
        s_pInstance = new TextureManager;
    return s_pInstance;
}

void TextureManager::load(std::string path, std::string id) {
    m_TextureMap[id] = IMG_LoadTexture(Game::getInstance()->getRenderer(), path.c_str());
}

void TextureManager::draw(std::string id, int x, int y, int w, int h){
    SDL_Rect srcRect, destRect;

    srcRect.x = srcRect.y = 0;
    SDL_QueryTexture(m_TextureMap[id],NULL, NULL, &srcRect.w, &srcRect.h);

    destRect.x = destRect.y = 0;
    if(w) destRect.w = w;
    else destRect.w = srcRect.w;

    if(h) destRect.h = h;
    else destRect.h = srcRect.h;

    SDL_RenderCopy(Game::getInstance()->getRenderer(), m_TextureMap[id], &srcRect, &destRect);
}