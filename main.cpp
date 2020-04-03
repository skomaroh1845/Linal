#include "Matrix.hpp"

#include <iostream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main() {
   // srand(time(NULL));
    Matrix M1(11);
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 25; j++)
            M1.setEl(i, j, rand() % 10 - 5);
    cout << M1 << endl;
    //cout << M1.get_inverse();
   // cout << M1.det();
    return 0;
}
