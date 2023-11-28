#include "Game.h"
#include "SpawnManager.h"
#include <type_traits>

    // static
SpawnManager *SpawnManager::s_pInstance = nullptr;

    // static
SpawnManager *SpawnManager::getInstance() {
    if(!s_pInstance) s_pInstance = new SpawnManager;
    return s_pInstance;
}


//template class SpawnManager::spawn<Enemy>;