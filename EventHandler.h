#pragma once

class EventHandler {
public:


    static EventHandler* getInstance();

private:
    static EventHandler* s_pInstance;
    EventHandler(){};
};

enum MouseButton{
    LEFT = 0,
    RIGHT = 1,
    MIDDLE = 2
};