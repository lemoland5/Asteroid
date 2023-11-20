#pragma once

class Vector2 {
public:
    int x;
    int y;

    Vector2();
    Vector2(int x, int y);

    float length() const;
    void normalise();

    Vector2 operator+(Vector2& v2) const;
    void operator+=(Vector2& v2);

    Vector2 operator*(float scalar) const;
    void operator*=(float scalar);


};

typedef Vector2 Vector2D;