#pragma  once

#include "Enemy.h"


class SpawnManager {
public:
    template<class T>
    void spawn(){
    if(std::is_same<T, Enemy>::value){
        Game::getInstance()->addGameObject<T>(new LoaderParams({0,0},100,100,0,"rocketbad",0,1,{},{},false,{}));
    }
}

    template<class T>
    void evalSpawn() {
        if(std::is_same<T, Enemy>::value){
            if(Game::getInstance()->getGameTicks()%100 == 0){
                spawn<Enemy>();
            }
        }
        else return;
    };

    static SpawnManager* getInstance();

private:
    static SpawnManager* s_pInstance;

    SpawnManager() {};
    ~SpawnManager() {};


};