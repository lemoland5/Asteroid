#include "EventHandler.h"
#include "Game.h"
#include <cstring>
#include <SDL.h>
#include <iostream>

// static
EventHandler* EventHandler::s_pInstance = nullptr;

    // static
EventHandler *EventHandler::getInstance() {
    if(!s_pInstance) s_pInstance = new EventHandler;
    return s_pInstance;
}

void EventHandler::update() {
    SDL_Event event;
    SDL_PollEvent(&event);

    std::cout<<m_MouseButtonState[LEFT]<<", "<<m_MouseButtonState[RIGHT]<<", "<<m_MouseButtonState[MIDDLE]<<"\n";

    switch (event.type) {
        case SDL_MOUSEBUTTONDOWN:
            if(event.button.button == SDL_BUTTON_LEFT) m_MouseButtonState[LEFT] = true;
            if(event.button.button == SDL_BUTTON_RIGHT) m_MouseButtonState[RIGHT] = true;
            if(event.button.button == SDL_BUTTON_MIDDLE) m_MouseButtonState[MIDDLE] = true;
            break;
        case SDL_MOUSEBUTTONUP:
            if(event.button.button == SDL_BUTTON_LEFT) m_MouseButtonState[LEFT] = false;
            if(event.button.button == SDL_BUTTON_RIGHT) m_MouseButtonState[RIGHT] = false;
            if(event.button.button == SDL_BUTTON_MIDDLE) m_MouseButtonState[MIDDLE] = false;
            break;
        case SDL_QUIT:
            Game::getInstance()->setRunning(false);
            break;
    }
}


EventHandler::EventHandler() {
    memset(m_MouseButtonState, false, sizeof(m_MouseButtonState));
}