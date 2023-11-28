#include "Vector.h"
#include <cmath>

Vector2::Vector2(): Point(){
    x = 0;
    y = 0;
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

void Vector2::operator=(int value) {
    x = y = value;
}




float degToRadian(float deg) {
    return deg * M_PI / 180;
}

Vector2 degToVector(float deg) {

    Vector2 vec(cos(degToRadian(deg)), sin(degToRadian(deg)));
    vec.normalise();
    return vec;
}

float radianToDeg(float rad) {
    return rad / M_PI * 180;
}

float getVectorAngle(Vector2 vector, Vector2 reference) {

    float dotProduct = vector.x * reference.x + vector.y * reference.y;

    double cosine_theta = dotProduct / (vector.length() * reference.length());
    double angleRadian = acos(cosine_theta);
    double angleDegrees = round(angleRadian * 180.0 / M_PI);

    if(vector.y > 0) angleDegrees *= -1;

    return angleDegrees;
}

bool hasIntersection(Circle circle, Point point){
    if(sqrt(((circle.x - point.x)*(circle.x - point.x))+((circle.y - point.y)*(circle.y - point.y))) <= circle.r) return true;
    return false;
}