#pragma once

class EventHandler {
public:

    void update();

    bool isMouseButtonDown(int button) {return m_MouseButtonState[button]; };

    static EventHandler* getInstance();

private:

    bool m_MouseButtonState[3];


    static EventHandler* s_pInstance;
    EventHandler();
};

enum MouseButton{
    LEFT = 0,
    RIGHT = 1,
    MIDDLE = 2
};