#pragma once

#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector.h"


class SDLGameObject: public GameObject {
public:
    virtual void draw();
    virtual void update();
    virtual void clean();

    [[nodiscard]] bool isMarkedForDeletion() {return m_MarkedForDeletion; };

    SDLGameObject(const LoaderParams* params);
    virtual ~SDLGameObject(){};

protected:
    bool m_MarkedForDeletion;

    Vector2 m_Position;
    float m_Width;
    float m_Height;
    float m_Spin;

    float m_Angle;          // Heading
    float m_Speed;
    Vector2 m_Velocity;
    Vector2 m_Acceleration;

    bool m_CanMove;
    bool m_CanShoot;
    bool m_IsMoving;

    std::string m_TextureId;


};