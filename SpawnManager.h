#pragma  once

#include "Enemy.h"
#include <iostream>


class SpawnManager {
public:
    template<class T>
    void spawn(){
        if(std::is_same<T, Enemy>::value){
            Point spawnCandidate(Game::getInstance()->getWindowWidth()*((rand()%101)/100.0f), Game::getInstance()->getWindowHeight()*((rand()%101)/100.0f));
            Circle playerCircle(Game::getInstance()->getPlayer()->getPosition().x, Game::getInstance()->getPlayer()->getPosition().y, 150);

            std::cout<<"Point: "<<spawnCandidate.x<<", "<<spawnCandidate.y<<" --- ";
            std::cout<<"Circle: "<<playerCircle.x<<", "<<playerCircle.y<<", "<<playerCircle.r<<" --- ";
            std::cout<<(hasIntersection(playerCircle, spawnCandidate) ? "Collides": "Does not collide")<<"\n";
            if(hasIntersection(playerCircle, spawnCandidate)){
                spawnCandidate.x = spawnCandidate.y = 0;
            }

            Game::getInstance()->addGameObject<T>(new LoaderParams({spawnCandidate.x, spawnCandidate.y},70,70,0,"rocketbad",0,1.75,{},{},false,{}));
        }
    }

    template<class T>
    void evalSpawn() {
        if(std::is_same<T, Enemy>::value){
            if(Game::getInstance()->getGameTicks()%80 == 0){
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