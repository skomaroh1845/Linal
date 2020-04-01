#ifndef vector2D
#define vector2D

#include <iostream>

class Vector2D {
private:
    int x;
    int y;
public:
    // ������������
    Vector2D();
    Vector2D(int x, int y);

    // ����������
    ~Vector2D();

    // ��������� ���������
    int getX() const;
    int getY() const;

    // ������� ���������
    void setX(int x);
    void setY(int y);

    // ��������� ���� �������� �� ���������
    bool operator== (const Vector2D& v2) const;

    // ����������� ��������
    bool operator!= (const Vector2D& v2) const;

    // ����� ���� ��������, �������� ������� �� ��������, ������������ ����� ������
    Vector2D operator+ (const Vector2D& v2) const;

    // ��������� ��������, �������� ������� �� ��������, ������������ ����� ������
    Vector2D operator- (const Vector2D& v2) const;

    // �������� ��������� ������� �� ������, �������� ������ �� ��������, ������������ ����� ������
    Vector2D operator* (const int a) const;
};

// ��������� ������� �� ������
Vector2D operator* (int a, const Vector2D& v);

// ����� �������, ��������� ������ � ������� (1; 1)
std::ostream& operator<<(std::ostream& os, const Vector2D& v);

// ������ �������, ������ ������ ��� ���������� ��� ���������
std::istream& operator>>(std::istream &is, Vector2D &v);

#endif //vector2D
