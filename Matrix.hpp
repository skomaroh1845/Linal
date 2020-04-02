#ifndef Matrix_HPP
#define Matrix_HPP

#include <iostream>

using namespace std;

class Matrix {
private:
    int m,n; // m - amount of strings, n - amount of columns
    float **arr;
public:
    Matrix(int m, int n); // init null matrix m*n

    Matrix(int n); // init unit matrix

    Matrix(int m, int n, float **arr); // init matrix m*n with elements from **arr

    Matrix(const Matrix& M); // copying matrix M

    ~Matrix();

    float getEl(int i, int j) const; // get element from i-string and j-column

    void setEl(int i, int j, float a); // set element in i-string and j-column

    int getStrSize() const; // get number of strings

    int getColSize() const; // get number of columns

    void resize_m(int new_i, int new_j); // set new size if matrix

    Matrix get_inverse() const; // get inverse matrix

    float det() const; // get matrix determinant;

    Matrix minor_ij(int i2, int j2) const; // minor for element(i,j)

    //overload operators

    Matrix operator+ (const Matrix& M);

    void operator+= (const Matrix& M);

    Matrix operator- (const Matrix& M);

    void operator-= (const Matrix& M);

    void operator= (const Matrix& M);

    Matrix operator* (const Matrix& M);

    Matrix operator* (float a);

    void operator*= (float a);

    bool operator== (const Matrix& M);

    bool operator!= (const Matrix& M);

    // + += - -= = * *= == != << >>
};

Matrix operator* (float a, const Matrix& M);

ostream& operator << (ostream& o, const Matrix& M);

istream& operator >> (istream& i, Matrix& M);

#endif // Matrix_H
