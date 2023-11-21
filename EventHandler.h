#pragma once
#include <SDL.h>

class EventHandler {
public:

    void update();

    // Getters
    [[nodiscard]] bool isMouseButtonDown(int button) {return m_MouseButtonState[button]; };
    [[nodiscard]] bool isKeyboardKeyDown(SDL_Scancode key) {return m_KeyboardState[key]; };

    static EventHandler* getInstance();

private:

    const Uint8* m_KeyboardState;
    bool m_MouseButtonState[3];


    static EventHandler* s_pInstance;
    EventHandler();
};

enum MouseButton{
    LEFT = 0,
    RIGHT = 1,
    MIDDLE = 2
};