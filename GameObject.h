#pragma once

class GameObject {
public:
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;

    GameObject(){};
};