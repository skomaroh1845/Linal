#include "Matrix.hpp"

#include <iostream>
#include <iomanip>

using namespace std;

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
    this->m = n;
    this->n = n;
    this->arr = new float* [n];
    for (int i = 0; i < n; i++)
        this->arr[i] = new float [n];
    for (int i = 0; i < n; i++)
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
    this->m = M.getStrSize();
    this->n = M.getColSize();
    this->arr = new float* [this->m];
    for (int i = 0; i < this->m; i++)
        this->arr[i] = new float [this->n];
    for (int i = 0; i < this->m; i++)
        for (int j = 0; j < this->n; j++) {
            this->arr[i][j] = M.getEl(i,j);
        }
}; // copying matrix M

Matrix::~Matrix() {
    for (int i = 0; i < this->m; i++)
        delete[] this->arr[i];
    delete[] this->arr;
};

float Matrix::getEl(int i, int j) const {
    if (i < this->m && j < this->n) return this->arr[i][j];
    return 0;
}; // get element from i-string and j-column

void Matrix::setEl(int i, int j, float a) {
    if (i < this->m && j < this->n) this->arr[i][j] = a;
}; // set element in i-string and j-column

int Matrix::getStrSize() const {
    return this->m;
}; // get number of strings

int Matrix::getColSize() const {
    return this->n;
}; // get number of columns

void Matrix::resize_m(int new_i, int new_j) {
    //save old matrix
    int k,l;
    if (new_i > this->m) k = this->m;
        else k = new_i;
    if (new_j > this->n) l = this->n;
        else l = new_j;
    float** Arr;
    Arr = new float* [k];
    for (int i = 0; i < k; i++)
        Arr[i] = new float[l];
    for (int i = 0; i < k; i++)
        for (int j = 0; j < l; j++) {
             Arr[i][j] = this->arr[i][j];
        }

    //freeing up memory
    for (int i = 0; i < this->m; i++)
        delete[] this->arr[i];
    delete[] this->arr;

    //new memory allocation
    this->arr = new float* [new_i];
    for (int i = 0; i < new_i; i++)
        this->arr[i] = new float [new_j];

    //push old elements
    for (int i = 0; i < new_i; i++)
        for (int j = 0; j < new_j; j++) {
            if (i >= k || j >= l) this->arr[i][j] = 0;
            else this->arr[i][j] = Arr[i][j];
        }
    for (int i = 0; i < k; i++)
        delete[] Arr[i];
    delete[] Arr;

    this->m = new_i;
    this->n = new_j;
}; // set new size if matrix

Matrix Matrix::minor_ij(int i2, int j2) const {
    if (i2 >= this->m || j2 >= this->n) return 0;
    float **Arr;
    Arr = new float* [this->m - 1];
    for (int i = 0; i < this->m - 1; i++)
        Arr[i] = new float [this->n - 1];

    int i1 = 0, j1= 0;
    for (int i = 0; i < this->m; i++) {
        for (int j = 0; j < this->n; j++) {
            if (i != i2 && j != j2) {
                Arr[i1][j1] = this->arr[i][j];
                j1++;
            }
        }
        if (i != i2) {i1++; j1 = 0;}
    }
    Matrix M(this->m - 1,this->n - 1, Arr);
    for (int i = 0; i < this->m - 1; i++)
        delete[] Arr[i];
    delete[] Arr;
    return M;
}

Matrix Matrix::get_inverse() const {
    if (this->m == this->n) {
        Matrix M(this->m, this->n);
        float detA = this->det();
        if (detA == 0) return 0;
        for (int i = 0; i < this->m; i ++)
            for (int j = 0; j < this->n; j ++) {
                float x = this->minor_ij(j, i).det() / detA;
                if ((i + j)%2) x = x*(-1);
                M.setEl(i, j, x);
            }
        return M;
    }
    return 0;
}; // get inverse matrix for M

float Matrix::det() const{
    if (this->m == this->n) {
        if (this->m == 2) return (this->arr[0][0]*this->arr[1][1] - this->arr[1][0]*this->arr[0][1]);
        float detM = 0;
        for (int j = 0; j < this->n; j++) {
            float s = this->arr[0][j] * this->minor_ij(0, j).det();
            if (j % 2) s = s*(-1);
            detM += s;
        }
        return detM;
    }
    return 0;
}; // determinant

    //overload operators

Matrix Matrix::operator+(const Matrix& M) {
    if (this->m == M.getStrSize() && this->n == M.getColSize()) {
        float **Arr;
        Arr = new float* [this->m];
        for (int i = 0; i < this->m; i++)
            Arr[i] = new float [this->n];

        for (int i = 0; i < this->m; i++)
            for (int j = 0; j < this->n; j++) {
                Arr[i][j] = this->arr[i][j] + M.getEl(i,j);
            }
        Matrix Sum(this->m, this->n, Arr);
        for (int i = 0; i < this->m; i++)
            delete[] Arr[i];
        delete[] Arr;
        return Sum;
    }
   // Matrix M();
    return 0;
};

void Matrix::operator=(const Matrix& M) {
    if (this->m == M.getStrSize() && this->n == M.getColSize()) {
        for (int i = 0; i < this->m; i++)
            for (int j = 0; j < this->n; j++) {
                this->arr[i][j] = M.getEl(i,j);
            }
    }
};

void Matrix::operator+=(const Matrix& M) {
    if (this->m == M.getStrSize() && this->n == M.getColSize()) {
        for (int i = 0; i < this->m; i++)
            for (int j = 0; j < this->n; j++) {
                this->arr[i][j] += M.getEl(i,j);
            }
    }
};

Matrix Matrix::operator-(const Matrix& M) {
    if (this->m == M.getStrSize() && this->n == M.getColSize()) {
        float **Arr;
        Arr = new float* [this->m];
        for (int i = 0; i < this->m; i++)
            Arr[i] = new float [this->n];

        for (int i = 0; i < this->m; i++)
            for (int j = 0; j < this->n; j++) {
                Arr[i][j] = this->arr[i][j] - M.getEl(i,j);
            }
        Matrix Sum(this->m, this->n, Arr);
        for (int i = 0; i < this->m; i++)
            delete[] Arr[i];
        delete[] Arr;
        return Sum;
    }
  //  Matrix M;
    return 0;
};

void Matrix::operator-=(const Matrix& M) {
    if (this->m == M.getStrSize() && this->n == M.getColSize()) {
        for (int i = 0; i < this->m; i++)
            for (int j = 0; j < this->n; j++) {
                this->arr[i][j] -= M.getEl(i,j);
            }
    }
};

Matrix Matrix::operator*(const Matrix& M) {
    if (this->n == M.getStrSize()) {
        float **Arr;
        Arr = new float* [this->m];
        for (int i = 0; i < this->m; i++)
            Arr[i] = new float [M.getColSize()];

        for (int i = 0; i < this->m; i++)
            for (int j = 0; j < M.getColSize(); j++) {
                Arr[i][j] = 0;
            }

        for (int i = 0; i < M.getColSize(); i++) {
            for (int j = 0; j < this->m; j++) {
                for (int k = 0; k < this->n; k++) {
                    Arr[j][i] += this->arr[j][k] * M.getEl(k, i);
                }
            }
        }

        Matrix Mult(this->m, M.getColSize(), Arr);
        for (int i = 0; i < this->m; i++)
            delete[] Arr[i];
        delete[] Arr;
        return Mult;
    }
   // Matrix M;
    return 0;
};

Matrix Matrix::operator*(float a) {
    float **Arr;
    Arr = new float* [this->m];
    for (int i = 0; i < this->m; i++)
        Arr[i] = new float [this->n];

    for (int i = 0; i < this->m; i++)
        for (int j = 0; j < this->n; j++) {
            Arr[i][j] = this->arr[i][j] * a;
        }
    Matrix Mult(this->m, this->n, Arr);
    for (int i = 0; i < this->m; i++)
        delete[] Arr[i];
    delete[] Arr;
    return Mult;
};

void Matrix::operator*=(float a) {
    for (int i = 0; i < this->m; i++)
        for (int j = 0; j < this->n; j++) {
            this->arr[i][j] *= a;
        }
};

bool Matrix::operator==(const Matrix& M) {
    if (this->m == M.getStrSize() && this->n == M.getColSize()) {
        for (int i = 0; i < this->m; i++)
            for (int j = 0; j < this->n; j++) {
                if (this->arr[i][j] != M.getEl(i, j)) return false;
            }
        return true;
    }
    return false;
};

bool Matrix::operator!=(const Matrix& M) {
    if (this->m == M.getStrSize() && this->n == M.getColSize()) {
        for (int i = 0; i < this->m; i++)
            for (int j = 0; j < this->n; j++) {
                if (this->arr[i][j] != M.getEl(i, j)) return true;
            }
        return false;
    }
    return true;
};

Matrix operator* (float a, const Matrix& M) {
    float **Arr;
    Arr = new float* [M.getStrSize()];
    for (int i = 0; i < M.getStrSize(); i++)
        Arr[i] = new float [M.getColSize()];

    for (int i = 0; i < M.getStrSize(); i++)
        for (int j = 0; j < M.getColSize(); j++) {
            Arr[i][j] = M.getEl(i, j) * a;
        }
    Matrix Mult(M.getStrSize(), M.getColSize(), Arr);
    for (int i = 0; i < M.getStrSize(); i++)
        delete[] Arr[i];
    delete[] Arr;
    return Mult;
};

ostream& operator << (ostream& o, const Matrix& M) {
    for (int i = 0; i < M.getStrSize(); i++) {
        for (int j = 0; j < M.getColSize(); j++) {
            o << setw(4) << M.getEl(i, j) << " ";
        }
        o << endl << endl;
    }
    return o;
};

istream& operator >> (istream& in, Matrix& M) {
    for (int i = 0; i < M.getStrSize(); i++) {
        for (int j = 0; j < M.getColSize(); j++) {
            float x;
            in >> x;
            M.setEl(i, j, x);
        }
    }
    return in;
};
