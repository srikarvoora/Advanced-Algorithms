#include <iostream>
using namespace std;

//Sparse Matrix using array

class SparseMatrix {
private:
    int rows, cols;
    int nonZeroCount;
    int** matrix;

public:
    SparseMatrix(int r, int c) {
        rows = r;
        cols = c;
        nonZeroCount = 0;

        // Allocate memory for the matrix
        matrix = new int*[rows];
        for (int i = 0; i < rows; i++) {
            matrix[i] = new int[cols];
            for (int j = 0; j < cols; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    void insert(int row, int col, int value) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            matrix[row][col] = value;
            if (value != 0) {
                nonZeroCount++;
            }
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    int getNonZeroCount() {
        return nonZeroCount;
    }

    ~SparseMatrix() {
        // Deallocate memory for the matrix
        for (int i = 0; i < rows; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

int main() {
    SparseMatrix matrix(3, 3);
    matrix.insert(0, 0, 1);
    matrix.insert(0, 1, 0);
    matrix.insert(0, 2, 0);
    matrix.insert(1, 0, 0);
    matrix.insert(1, 1, 2);
    matrix.insert(1, 2, 0);
    matrix.insert(2, 0, 0);
    matrix.insert(2, 1, 0);
    matrix.insert(2, 2, 3);

    matrix.display();
    cout << "Non-zero count: " << matrix.getNonZeroCount() << endl;

    return 0;
}
