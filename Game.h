#pragma once

#include "Player.h"
#include <SDL.h>

class Game {
public:

    // Main wakeup call
    bool init(const char* windowname, int x, int y, int w, int h, SDL_WindowFlags flags);

    void handleEvents();    // Input
    void update();          // Update
    void render();          // Render

    void clean();           // Cleanup mpr, mpw

    // Getters
    [[nodiscard]] bool isRunning() const {return m_Running; };
    [[nodiscard]] SDL_Renderer* getRenderer() const {return m_pRenderer; };

    static Game* getInstance(); // Singleton

private:
    static Game* s_pInstance;   // Singleton

    SDL_Window* m_pWindow;      // mpw
    SDL_Renderer* m_pRenderer;  // mpr

    GameObject* m_pPlayer;


    bool m_Running;


    Game();
    ~Game();

};