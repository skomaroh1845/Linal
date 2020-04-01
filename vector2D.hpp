#ifndef vector2D
#define vector2D

#include <iostream>

class Vector2D {
private:
    float x, y;
public:
    Vector2D();

    Vector2D(float x, float y);

    ~Vector2D();

    float getX() const;

    float getY() const;

    void setX(float x);

    void setY(float y);

    void rotate_R(float angle);

    void rotate_L(float angle);

    bool operator== (const Vector2D& v2) const;

    bool operator!= (const Vector2D& v2) const;

    Vector2D operator+ (const Vector2D& v2) const;

    Vector2D operator- (const Vector2D& v2) const;

    Vector2D operator* (const float a) const;

    float operator* (const Vector2D& a) const;
};

Vector2D operator* (float a, const Vector2D& v);

std::ostream& operator<<(std::ostream& os, const Vector2D& v);

std::istream& operator>>(std::istream &is, Vector2D &v);

#endif //vector2D
