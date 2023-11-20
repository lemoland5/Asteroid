#include "EventHandler.h"

    // static
EventHandler* EventHandler::s_pInstance = nullptr;

    // static
EventHandler *EventHandler::getInstance() {
    if(!s_pInstance) s_pInstance = new EventHandler;
    return s_pInstance;
}
