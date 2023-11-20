#pragma once

#define M_PI 3.1415

class Vector2 {
public:
    float x;
    float y;

    Vector2();
    Vector2(float x, float y);

    float length() const;
    void normalise();

    Vector2 operator+(Vector2& v2) const;
    void operator+=(Vector2& v2);

    Vector2 operator*(float scalar) const;
    void operator*=(float scalar);

    void operator=(int value);

    friend float degToRadian(float deg);
    friend Vector2 degToVector(float deg);

};

Vector2 degToVector(float deg);


typedef Vector2 Vector2D;