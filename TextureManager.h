#pragma once

#include <map>
#include <SDL.h>
#include <string>
class TextureManager {
public:
    void load(std::string path, std::string id);
    void draw(std::string id, int x, int y, int w = NULL, int h = NULL);


    static TextureManager* getInstance();   // Singleton.
private:
    static TextureManager* s_pInstance;     // Singleton.

    std::map<std::string, SDL_Texture*> m_TextureMap;   // Texturekeeping


};