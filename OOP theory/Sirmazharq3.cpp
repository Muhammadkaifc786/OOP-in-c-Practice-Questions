#include <iostream>

using namespace std;

class matrixType {
private:
    int** matrix;
    int rows, cols;

public:
    matrixType(int rows, int cols) : rows(rows), cols(cols) {
        // Allocate memory for the matrix
        matrix = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            matrix[i] = new int[cols];
        }

        // Initialize the matrix with zeros
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                matrix[i][j] = 0;
            }
        }
    }

    ~matrixType() {
        // Deallocate memory for the matrix
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    void setElement(int row, int col, int value) {
        matrix[row][col] = value;
    }

    matrixType operator+(const matrixType& other) const {
        matrixType result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    matrixType operator-(const matrixType& other) const {
        matrixType result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }

    matrixType operator*(const matrixType& other) const {
        if (cols != other.rows) {
            // Matrices cannot be multiplied
            cerr << "Error: Incompatible matrix sizes for multiplication." << endl;
            return matrixType(0, 0);
        }

        matrixType result(rows, other.cols);
        for (int i = 0; i < rows; ++i) {
            for (int k = 0; k < other.cols; ++k) {
                for (int j = 0; j < cols; ++j) {
                    result.matrix[i][k] += matrix[i][j] * other.matrix[j][k];
                }
            }
        }
        return result;
    }
};

int main() {
    matrixType A(2, 3);
    matrixType B(3, 2);

    // Set elements for matrices A and B
    A.setElement(0, 0, 1);
    A.setElement(0, 1, 2);
    A.setElement(0, 2, 3);
    A.setElement(1, 0, 4);
    A.setElement(1, 1, 5);
    A.setElement(1, 2, 6);

    B.setElement(0, 0, 7);
    B.setElement(0, 1, 8);
    B.setElement(1, 0, 9);
    B.setElement(1, 1, 10);
    B.setElement(2, 0, 11);
    B.setElement(2, 1, 12);

    // Test addition, subtraction, and multiplication
    matrixType C = A + B;
    matrixType D = A - B;
    matrixType E = A * B;

    // Output matrices
    cout << "Matrix A:" << endl;
    for (int i = 0; i < A.rows; ++i) {
        for (int j = 0; j < A.cols; ++j) {
            cout << A.matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix B:" << endl;
    for (int i = 0; i < B.rows; ++i) {
        for (int j = 0; j < B.cols; ++j) {
            cout << B.matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix A + B:" << endl;
    for (int i = 0; i < C.rows; ++i) {
        for (int j = 0; j < C.cols; ++j) {
            cout << C.matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix A - B:" << endl;
    for (int i = 0; i < D.rows; ++i) {
        for (int j = 0; j < D.cols; ++j) {
            cout << D.matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Matrix A * B:" << endl;
    for (int i = 0; i < E.rows; ++i) {
        for (int j = 0; j < E.cols; ++j) {
            cout << E.matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
