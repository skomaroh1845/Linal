#include "Matrix.hpp"


Matrix::Matrix() {
    this->m = 0;
    this->n = 0;
    this->arr = NULL;
}; // init empty matrix object

Matrix::Matrix(int m, int n) {
    this->m = m;
    this->n = n;
    this->arr = new float* [m];
    for (int i = 0; i < m; i++)
        this->arr[i] = new float [n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            this->arr[i][j] = 0;
}; // init null matrix m*n

Matrix::Matrix(int n) {
    this->m = m;
    this->n = n;
    this->arr = new float* [m];
    for (int i = 0; i < m; i++)
        this->arr[i] = new float [n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (i != j) this->arr[i][j] = 0;
            else this->arr[i][j] = 1;
        }
}; // init unit matrix

Matrix::Matrix(int m, int n, float **Arr) {
    this->m = m;
    this->n = n;
    this->arr = new float* [m];
    for (int i = 0; i < m; i++)
        this->arr[i] = new float [n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            this->arr[i][j] = Arr[i][j];
        }
}; // init matrix m*n with elements from **arr

Matrix::Matrix(const Matrix& M) {
    this->m = m;
    this->n = n;
    this->arr = new float* [m];
    for (int i = 0; i < m; i++)
        this->arr[i] = new float [n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            this->arr[i][j] = M.getEl(i,j);
        }
}; // copying matrix M

Matrix::~Matrix() {
    for (int i = 0; i < this->m; i++)
        delete[] this->arr[i];
    delete[] this->arr;
};

float Matrix::getEl(int i, int j) const {
    return this->arr[i][j];
}; // get element from i-string and j-column

void Matrix::setEl(int i, int j, float a); // set element in i-string and j-column

int Matrix::getStrSize() const; // get number of strings

int Matrix::getColSize() const; // get number of columns

void Matrix::resize_m(int new_i, int new_j); // set new size if matrix

Matrix Matrix::get_inverse(const Matrix& M); // get inverse matrix for M

    //overload operators

Matrix Matrix::operator+ (const Matrix& M);

Matrix Matrix::operator+= (const Matrix& M);

Matrix Matrix::operator- (const Matrix& M);

Matrix Matrix::operator-= (const Matrix& M);

void Matrix::operator= (const Matrix& M);

Matrix Matrix::operator* (const Matrix& M);

Matrix Matrix::operator* (float a);

Matrix Matrix::operator*= (float a);

bool Matrix::operator== (const Matrix& M);

bool Matrix::operator!= (const Matrix& M);

Matrix operator* (float a, const Matrix& M);

ostream& operator << (ostream& o, const Matrix& M);

istream& operator >> (istream& i, Matrix& M);
