#pragma once

#define M_PI 3.1415926535

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
    friend float radianToDeg(float rad);

    friend float getVectorAngle(Vector2 vector, Vector2 reference);


};
float degToRadian(float deg);
float radianToDeg(float rad);
Vector2 degToVector(float deg);

float getVectorAngle(Vector2 vector, Vector2 reference);


typedef Vector2 Vector2D;