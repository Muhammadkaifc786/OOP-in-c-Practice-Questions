#include <iostream>
#include <vector>

using namespace std;

class matrixType {
private:
    vector<vector<int>> matrix;
    int rows, cols;

public:
    matrixType(int rows, int cols) : rows(rows), cols(cols) {
        matrix.resize(rows, vector<int>(cols, 0));
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

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    matrixType A(2, 3);
    matrixType B(2, 3);

    // Set elements for matrices A and B
    A.setElement(0, 0, 1);
    A.setElement(0, 1, 2);
    A.setElement(0, 2, 3);
    A.setElement(1, 0, 4);
    A.setElement(1, 1, 5);
    A.setElement(1, 2, 6);

    B.setElement(0, 0, 7);
    B.setElement(0, 1, 8);
    B.setElement(0, 2, 9);
    B.setElement(1, 0, 10);
    B.setElement(1, 1, 11);
    B.setElement(1, 2, 12);

    // Test addition, subtraction, and multiplication
    matrixType C = A + B;
    matrixType D = A - B;
    matrixType E = A * B;

    // Output matrices
    cout << "Matrix A:" << endl;
    A.display();

    cout << "Matrix B:" << endl;
    B.display();

    cout << "Matrix A + B:" << endl;
    C.display();

    cout << "Matrix A - B:" << endl;
    D.display();

    cout << "Matrix A * B:" << endl;
    E.display();

    return 0;
}
