#include "Vector.h"
#include <cmath>

Vector2::Vector2(){
    x = 0;
    y = 0;
}

Vector2::Vector2(float x, float y){
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
    double dot_product = vector.x * reference.x + vector.y * reference.y;
    double magnitude_v = sqrt(vector.x * vector.x + vector.y * vector.y);
    double magnitude_u = sqrt(reference.x * reference.x + reference.y * reference.y);

    double cosine_theta = dot_product / (magnitude_v * magnitude_u);
    double angle_radians = acos(cosine_theta);
    double angle_degrees = round(angle_radians * 180.0 / M_PI);

    return fmod(360.0f, angle_degrees);
}

