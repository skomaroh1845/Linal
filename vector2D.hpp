#ifndef vector2D
#define vector2D

#include <iostream>

class Vector2D {
private:
    int x;
    int y;
public:
    //  онструкторы
    Vector2D();
    Vector2D(int x, int y);

    // ƒеструктор
    ~Vector2D();

    // ѕолучение координат
    int getX() const;
    int getY() const;

    // «адание координат
    void setX(int x);
    void setY(int y);

    // сравнение двух векторов на равенство
    bool operator== (const Vector2D& v2) const;

    // неравенство векторов
    bool operator!= (const Vector2D& v2) const;

    // —умма двух векторов, исходные вектора не мен€ютс€, возвращаетс€ новый вектор
    Vector2D operator+ (const Vector2D& v2) const;

    // ¬ычитание векторов, исходные вектора не мен€ютс€, возвращаетс€ новый вектор
    Vector2D operator- (const Vector2D& v2) const;

    // ќператор умножени€ вектора на скал€р, исходный вектор не мен€етс€, возвращаетс€ новый вектор
    Vector2D operator* (const int a) const;
};

// ”множение скал€ра на вектор
Vector2D operator* (int a, const Vector2D& v);

// ¬ывод вектора, ожидаетс€ строго в формате (1; 1)
std::ostream& operator<<(std::ostream& os, const Vector2D& v);

// „тение вектора, читает просто две координаты без хитростей
std::istream& operator>>(std::istream &is, Vector2D &v);

#endif //vector2D
