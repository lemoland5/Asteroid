#pragma once

#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector.h"


class SDLGameObject: public GameObject {
public:
    virtual void draw();
    virtual void update();

    [[nodiscard]] bool isMarkedForDeletion() {return m_MarkedForDeletion; };

    SDLGameObject(const LoaderParams* params);
    virtual ~SDLGameObject(){};

protected:
    bool m_MarkedForDeletion;

    Vector2 m_Position;
    int m_Width;
    int m_Height;
    float m_Angle;    // angle

    float m_Speed;
    Vector2 m_Velocity;
    Vector2 m_Acceleration;

    std::string m_TextureId;


};