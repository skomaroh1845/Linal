#include "vector2D.hpp"

using namespace std;

Vector2D::Vector2D() {
    this->x = 0;
    this->y = 0;
};

Vector2D::Vector2D(int x, int y) {
    this->x = x;
    this->y = y;
};

Vector2D::~Vector2D() {};

int Vector2D::getX() const {
    return this->x;
};

int Vector2D::getY() const {
    return this->y;
};

void Vector2D::setX(int x) {
    this->x = x;
};

void Vector2D::setY(int y) {
    this->y = y;
};

bool Vector2D::operator== (const Vector2D& v2) const {
    if (this->x == v2.x && this->y == v2.y) return true;
    else return false;
};

bool Vector2D::operator!= (const Vector2D& v2) const {
    if (this->x == v2.x && this->y == v2.y) return false;
    else return true;
};

Vector2D Vector2D::operator+ (const Vector2D& v2) const {
    Vector2D v3;
    v3.setX(this->x + v2.getX());
    v3.setY(this->y + v2.getY());
    return v3;
};

Vector2D Vector2D::operator- (const Vector2D& v2) const {
    Vector2D v3;
    v3.setX(this->x - v2.getX());
    v3.setY(this->y - v2.getY());
    return v3;
};

Vector2D Vector2D::operator* (const int a) const {
    Vector2D v3;
    v3.setX(this->x * a);
    v3.setY(this->y * a);
    return v3;
};

Vector2D operator* (int a, const Vector2D& v) {
    Vector2D v3;
    v3.setX(a * v.getX());
    v3.setY(a * v.getY());
    return v3;
};

std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
};

std::istream& operator>>(std::istream &is, Vector2D &v) {
    int x,y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
};
