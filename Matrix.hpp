#ifndef Matrix
#define Matrix

#include <iostream>

class Matrix {
private:
    int m,n // m - amount of strings, n - amount of columns
    float **arr;
public:
    Matrix(); // init empty matrix object

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

    Matrix get_inverse(const Matrix& M); // get inverse matrix for M

    float det(const Matrix& M); // get determinant of matrix

    //overload operators

    Matrix operator+ (const Matrix& M);

    Matrix operator+= (const Matrix& M);

    Matrix operator- (const Matrix& M);

    Matrix operator-= (const Matrix& M);

    void operator= (const Matrix& M);

    Matrix operator* (const Matrix& M);

    Matrix operator* (float a);

    Matrix operator*= (float a);

    bool operator== (const Matrix& M);

    bool operator!= (const Matrix& M);

    // + += - -= = * *= == != << >>
};

Matrix operator* (float a, const Matrix& M);

ostream& operator << (ostream& o, const Matrix& M);

istream& operator >> (istream& i, Matrix& M);

#endif // Matrix
