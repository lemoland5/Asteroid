#pragma once

#include "GameObject.h"
#include "LoaderParams.h"
#include "Vector.h"
#include <stack>


class SDLGameObject: public GameObject {
public:
    virtual void draw();
    virtual void update();
    virtual void handleCollisions() = 0;
    virtual void clean();

    [[nodiscard]] bool isMarkedForDeletion() {return m_MarkedForDeletion; };
    [[nodiscard]] bool isPlayerDamage() {return  m_IsPlayerDamage; };
    [[nodiscard]] bool isEnemyDamage() {return  m_IsEnemyDamage; };

    SDLGameObject(const LoaderParams* params);
    virtual ~SDLGameObject(){};

protected:
    bool m_MarkedForDeletion;

    Vector2 m_Position;
    float m_Width;
    float m_Height;
    float m_Spin;           // Visual angle

    float m_Angle;          // Heading angle
    float m_Speed;
    Vector2 m_Velocity;
    Vector2 m_Acceleration;

    bool m_CanMove;
    bool m_CanShoot;
    bool m_IsMoving;

    bool m_IsPlayerDamage;
    bool m_IsEnemyDamage;

    int m_ParticleDelay;
    int m_UpdateCounter;

    std::stack<SDLGameObject*> m_CollisionStack;

    std::string m_TextureId;


};