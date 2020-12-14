#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>

using namespace std;

class Matrix {
public:
    Matrix() {
        rows = 0;
        cols = 0;
    }
    Matrix(int numRows, int numCols) {
        if (numRows < 0 || numCols < 0) {
            throw out_of_range("rows or cols can't be a negative");
        }
        if (numRows == 0 || numCols == 0) {
            numRows = numCols = 0;
        }
        
        rows = numRows;
        cols = numCols;

        for (int i = 0; i < numRows; i++) {
            matrix.push_back(vector<int>(numCols, 0));
        }
    }

    void Reset(int numRows, int numCols) {
        if (numRows < 0 || numCols < 0) {
            throw out_of_range("rows or cols can't be a negative");
        }
        
        rows = numRows;
        cols = numCols;

        vector<vector<int>> newMatrix;

        for (int i = 0; i < numRows; i++) {
            newMatrix.push_back(vector<int>(numCols, 0));
        }

        matrix = newMatrix;
    }

    int At(int row, int col) const {
        return matrix.at(row).at(col);
    }

    int& At(int row, int col) {
        return matrix.at(row).at(col);
    }

    int GetNumRows() const {
        return rows; 
    }

    int GetNumColumns() const {
        return cols;
    }

private:
    vector<vector<int>> matrix; 
    int rows;
    int cols;
};

istream& operator>>(istream& input, Matrix& m) {
    int rows, cols;
    input >> rows;
    input >> cols;

    Matrix newMatrix(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            input >> newMatrix.At(i, j);
        }
    }

    m = newMatrix;

    return input;
}

ostream& operator<<(ostream& output, const Matrix& m) {
    int rows = m.GetNumRows();
    int cols = m.GetNumColumns();

    output << rows << " " << cols << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            output << m.At(i, j) << " "; 
        }

        if (rows - i != 1) {
            output << endl;
        }
    }

    return output;
}

bool operator==(const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()) {
        return false;
    }

    for (int i = 0; i < lhs.GetNumRows(); i++) {
        for (int j = 0; j < lhs.GetNumColumns(); j++) {
            if (lhs.At(i, j) != rhs.At(i,j)) {
                return false;
            }
        }
    }

    return true;
}

Matrix operator+(const Matrix&lhs, const Matrix& rhs) {
    if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()) {
        throw invalid_argument("size of matrixes are not equal");
    }

    Matrix res(lhs.GetNumRows(), lhs.GetNumColumns());

    for (int i = 0; i < lhs.GetNumRows(); i++) {
        for (int j = 0; j < lhs.GetNumColumns(); j++) {
            res.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }

    return res;
}

int main() {
    Matrix one;
    Matrix two;
    
    cin >> one >> two;
    cout << one + two << endl;

    return 0;
}
