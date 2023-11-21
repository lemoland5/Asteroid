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

    destRect.x = x;
    destRect.y = y;
    if(w) destRect.w = w;
    else destRect.w = srcRect.w;

    if(h) destRect.h = h;
    else destRect.h = srcRect.h;

    SDL_RenderCopy(Game::getInstance()->getRenderer(), m_TextureMap[id], &srcRect, &destRect);
}

void
TextureManager::drawFrameEx(std::string id, int row, int column, int frameW, int frameH, int x, int y, int w, int h,
                            float angle) {
    SDL_Rect srcRect, destRect;

    srcRect.x = row * frameW;
    srcRect.y = column * frameH;

    srcRect.w = frameW;
    srcRect.h = frameH;

    destRect.x = x;
    destRect.y = y;
    destRect.w = w;
    destRect.h = h;


//    SDL_RenderCopy(Game::getInstance()->getRenderer(), m_TextureMap[id], &srcRect, &destRect);
    SDL_RenderCopyEx(Game::getInstance()->getRenderer(), m_TextureMap[id], &srcRect, &destRect, angle, 0, SDL_FLIP_NONE);
}
