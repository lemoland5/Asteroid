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
//
//template<class T>
//void SpawnManager::evalSpawn() {
//    if(std::is_same<T, Enemy>::value){
//        if(Game::getInstance()->getGameTicks()%100 == 0){
//            spawn<Enemy>();
//        }
//    }
//    else return;
//}

//template<class T>
//void SpawnManager::spawn() {
//    if(std::is_same<T, Enemy>::value){
//        Game::getInstance()->addGameObject<T>(new LoaderParams({0,0},100,100,0,"rocketbad",0,1,{},{},false,{}));
//    }
//}
