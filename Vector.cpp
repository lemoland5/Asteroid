#include "Vector.h"
#include <cmath>

Vector2::Vector2(){
    x = 0;
    y = 0;
}

Vector2::Vector2(int x, int y){
    this->x = x;
    this->y = y;
}

float Vector2::length() const {
    return sqrt(x*x + y*y);
}

void Vector2::normalise(){
    if(length() > 0)
        *this *= 1/length();
}

void Vector2::operator*=(float scalar) {
    x *= scalar;
    y *= scalar;
}

Vector2 Vector2::operator+(Vector2& v2) const {
    return Vector2(x + v2.x, y + v2.y);
}

void Vector2::operator+=(Vector2 &v2) {
    x += v2.x;
    y += v2.y;
}

Vector2 Vector2::operator*(float scalar) const {
    return Vector2(x*scalar, y*scalar);
}
