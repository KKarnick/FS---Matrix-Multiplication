
#include <iostream>

using namespace std;


void inputMatrix(int a[][10], int r, int c);
void matrixMult(int a[][10], int b[][10], int mult[][10], int r1, int r2, int c1, int c2);
void scalarMult(int a[][10], int res[][10], int x, int r, int c);
void displayMatrix(int a[][10], int r, int c);

int main() {
    int rA, cA, rB, cB, rC, cC;
    int matrixA[10][10];  //set 10 as row/col max for all to begin
    int matrixB[10][10];
    int matrixC[10][10];
    int matrixResult[10][10];

    cout << "Enter the number of rows for Matrix A: ";
    cin >> rA;
    cout << "Enter the number of columns for Matrix A : ";
    cin >> cA;
    inputMatrix(matrixA, rA, cA);
    cout << "Enter the number of rows for Matrix B: ";
    cin >> rB;
    cout << "Enter the number of columns for Matrix B:  ";
    cin >> cB;
    inputMatrix(matrixB, rB, cB);
    cout << "Enter the number of rows for Matrix C: ";
    cin >> rC;
    cout << "Enter the number of columns for Matrix C:  ";
    cin >> cC;
    inputMatrix(matrixC, rC, cC);

    cout << "Matrix A x Matrix B " << endl;
    matrixMult(matrixA, matrixB, matrixResult, rA, rB, cA, cB);
    cout << "Matrix B x Matrix A " << endl;
    matrixMult(matrixB, matrixA, matrixResult, rB, rA, cB, cA);
    cout << "Matrix C x Matrix B " << endl;
    matrixMult(matrixC, matrixB, matrixResult, rC, rB, cC, cB);
    cout << "2 * Matrix A " << endl;
    scalarMult(matrixA, matrixResult, 2, rA, cA);
    cout << "-4 * Matrix B " << endl;
    scalarMult(matrixB, matrixResult, -4, rB, cB);
}

void inputMatrix(int a[][10], int r, int c) {
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << "Enter element for position " << i + 1 << ", " << j + 1 << ": ";
            cin >> a[i][j];
        }
    }
    cout << endl;
}
void matrixMult(int a[][10], int b[][10], int mult[][10], int r1, int r2, int c1, int c2) {
    try {
        if (c1 != r2)         //check to be sure the matrices CAN be multiplied
            throw "INVALID MATRIX";
        for (int i = 0; i < 10; ++i) {     //set all values to 0 to start resulting matrix
            for (int j = 0; j < 10; ++j)
                mult[i][j] = 0;
        }
        for (int i = 0; i < r1; ++i) {   //each row of 1st matrix
            for (int j = 0; j < c2; ++j) {   //each column of second matrix
                for (int k = 0; k < c1; ++k)   //column position of 1st AND row position of 2nd (c1 and r2 MUST be equal)
                    mult[i][j] += a[i][k] * b[k][j];
            }
        }
        cout << "    The resulting Matrix is " << endl;
        displayMatrix(mult, r1, c2);
        cout << endl;
    }
    catch (string) {
        cout << "INVALID!  Number of columns in matrix1 does not match number of rows in matrix2." << endl;
    }
}
void scalarMult(int a[][10], int res[][10], int x, int r, int c) {
    for (int i = 0; i < 10; ++i) {     //set all values to 0 to start resulting matrix
        for (int j = 0; j < 10; ++j)
            res[i][j] = 0;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            res[i][j] = x * a[i][j];
    }
    displayMatrix(res, r, c);
    cout << endl;
}
void displayMatrix(int a[][10], int r, int c) {
    cout << endl;
    for (int i = 0; i < r; ++i) {
        cout << " |   ";
        for (int j = 0; j < c; ++j) {
            int spaceCount = 0;
            cout << a[i][j];
            int n = a[i][j];
            if (n > 9 && n < 100)
                spaceCount += 1;
            if (n < 0)
                spaceCount += 1;
            if (n > 99 || n < -10)
                spaceCount += 1;
            while (spaceCount < 3) {
                cout << " ";
                spaceCount++;
            }
        }
        cout << "|" << endl;
    }
}