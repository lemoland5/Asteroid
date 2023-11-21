#pragma once

#include <map>
#include <SDL.h>
#include <string>
class TextureManager {
public:
    void load(std::string path, std::string id);

    void draw(std::string id, int x, int y, int w = 0, int h = 0);
    void draw(SDL_Texture *texture, int x, int y, int w = 0, int h = 0);

    void drawFrameEx(std::string id, int row, int column, int frameW, int frameH, int x, int y, int w, int h, float angle);


    SDL_Texture* getTexture(std::string id){return m_TextureMap[id]; };
    static TextureManager* getInstance();   // Singleton.
private:
    static TextureManager* s_pInstance;     // Singleton.

    std::map<std::string, SDL_Texture*> m_TextureMap;   // Texturekeeping


};