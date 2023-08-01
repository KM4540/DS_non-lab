#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int r1, c1, r2, c2;

    cout << "Enter the Order of the First matrix..." << endl;
    cin >> r1 >> c1;
    cout << "Enter the Order of the Second matrix..." << endl;
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Invalid Order of matrix" << endl;
        return 1;
    }

    // Dynamic allocation of matrices using malloc
    int** mat1 = (int**)malloc(r1 * sizeof(int*));
    for (int i = 0; i < r1; i++)
        mat1[i] = (int*)malloc(c1 * sizeof(int));

    int** mat2 = (int**)malloc(r2 * sizeof(int*));
    for (int i = 0; i < r2; i++)
        mat2[i] = (int*)malloc(c2 * sizeof(int));

    int** res = (int**)malloc(r1 * sizeof(int*));
    for (int i = 0; i < r1; i++)
        res[i] = (int*)malloc(c2 * sizeof(int));

    // Input Matrix1
    cout << "Enter elements of Matrix 1:" << endl;
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> mat1[i][j];

    // Input Matrix2
    cout << "Enter elements of Matrix 2:" << endl;
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> mat2[i][j];
            
    // Computation (Multiplication)
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < c1; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }

    cout << "\nThe Multiplication of two matrices is:" << endl;
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << res[i][j] << "\t";
        cout << endl;
    }
}
