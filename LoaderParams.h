#pragma once

#include "Vector.h"
#include <string>

class LoaderParams {
public:
    LoaderParams(Vector2 pos, int w, int h, float angle, std::string id): m_Position(pos), m_Width(w), m_Height(h), m_Angle(angle), m_TextureId(id) {};

    Vector2 m_Position;
    int m_Width;
    int m_Height;
    float m_Angle;
    std::string m_TextureId;
};