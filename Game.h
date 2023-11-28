#pragma once

#include "Player.h"
#include "Particle.h"
#include <SDL.h>
#include <vector>

class Game {
public:

    // Main wakeup call
    bool init(const char* windowname, int x, int y, int w, int h, SDL_WindowFlags flags);

    void handleEvents();    // Input
    void update();          // Update
    void render();          // Render

    void clean();           // Cleanup mpr, mpw

    template<class T>
    void addGameObject(const LoaderParams *params) {
        m_GameObjects.push_back(new T(params));
    }

    // Setters
    void setRunning(bool r) {m_Running = r; };


    // Getters
    [[nodiscard]] bool isRunning() const {return m_Running; };
    [[nodiscard]] SDL_Renderer* getRenderer() const {return m_pRenderer; };
    [[nodiscard]] int getWindowWidth() const {return m_WindowWidth; };
    [[nodiscard]] int getWindowHeight() const {return m_WindowHeight; };
    [[nodiscard]] std::vector<SDLGameObject*> getGameObjects() const {return m_GameObjects; };
    [[nodiscard]] SDLGameObject* getPlayer() const {return m_GameObjects[0]; };
    [[nodiscard]] unsigned int getGameTicks() const {return m_GameTicks; };

    static Game* getInstance(); // Singleton

private:
    static Game* s_pInstance;   // Singleton

    SDL_Window* m_pWindow;      // mpw
    SDL_Renderer* m_pRenderer;  // mpr

    std::vector<SDLGameObject*> m_GameObjects;
//    GameObject* m_pPlayer;

    int m_WindowWidth;
    int m_WindowHeight;

    unsigned int m_GameTicks;

    bool m_Running;


    Game();
    ~Game();

};