#include <iostream>

using namespace std;

class Matrix {
private:
  int rows;
  int col;
  int **matrix; // Use double pointer for dynamic allocation

public:
  Matrix(int r, int c) : rows(r), col(c) {
    // Allocate memory for the matrix
    matrix = new int *[rows];
    for (int i = 0; i < rows; ++i) {
      matrix[i] = new int[col];
    }
  }

  ~Matrix() {
    // Deallocate memory for the matrix
    for (int i = 0; i < rows; ++i) {
      delete[] matrix[i];
    }
    delete[] matrix;
  }

  void setValue() {
    cout << "Enter Matrix Values:" << endl;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < col; j++) {
        cout << "Enter index[" << i << "][" << j << "]" << endl;
        cin >> matrix[i][j];
      }
    }
  }
  void operator +(Matrix &m){
    int arr[rows][col];
    int sum;
    for (size_t i = 0; i < rows; i++) {
      sum=0;
      for (size_t j = 0; j < col; j++) {
      sum=matrix[i][j]+m.matrix[i][j];
      arr[i][j]=sum;
      }
    }
    cout<<"Matrix Addition is:"<<endl;
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < col; j++) {
        cout<<arr[i][j];
        cout<<" ";
      }
      cout<<endl;
    }
  }
  void operator -(Matrix &m){
    int arr[rows][col];
    int sum;
    for (size_t i = 0; i < rows; i++) {
      sum=0;
      for (size_t j = 0; j < col; j++) {
      sum=matrix[i][j]-m.matrix[i][j];
      arr[i][j]=sum;
      }
    }
    cout<<"Matrix Subtraction is:"<<endl;
    for (size_t i = 0; i < rows; i++) {
      for (size_t j = 0; j < col; j++) {
        cout<<arr[i][j];
        cout<<" ";
      }
      cout<<endl;
    }
  }
};

int main() {
  // Example usage
  Matrix myMatrix(3, 3);
  myMatrix.setValue();
  Matrix b(3,3);
  cout<<"Enter Second Matrix.."<<endl;
  b.setValue();
  myMatrix+b;
  myMatrix-b;
  return 0;
}
// Matrix multiply(const Matrix &a, const Matrix &b) {
//   int aRows = a.rows;
//   int aCols = a.cols;
//   int bCols = b.cols;
//
//   Matrix result(aRows, bCols);
//
//   for (int i = 0; i < aRows; ++i) {
//     for (int j = 0; j < bCols; ++j) {
//       result.matrix[i][j] = 0;
//       for (int k = 0; k < aCols; ++k) {
//         result.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
//       }
//     }
//   }
//
//   return result;
// }
