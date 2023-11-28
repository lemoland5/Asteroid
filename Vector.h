#pragma once


#define M_PI 3.1415926535

class Point {
public:
    float x;
    float y;

    Point(float x, float y):x(x),y(y){};
    Point():x(0.0f),y(0.0f){};

};

class Vector2: public Point {
public:

    Vector2();
    Vector2(float x, float y): Point(x,y){};

    float length() const;
    void normalise();

    Vector2 operator+(Vector2& v2) const;
    void operator+=(Vector2& v2);

    Vector2 operator*(float scalar) const;
    void operator*=(float scalar);

    void operator=(int value);

};

class Circle: public Point{
public:
    float r;

    Circle(float x, float y, float r): Point(x,y), r(r){};
    Circle(): Point(), r(0){};
};

float degToRadian(float deg);
float radianToDeg(float rad);
Vector2 degToVector(float deg);

float getVectorAngle(Vector2 vector, Vector2 reference);
bool hasIntersection(Circle circle, Point point);


typedef Vector2 Vector2D;