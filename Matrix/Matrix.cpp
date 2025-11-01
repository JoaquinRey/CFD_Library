#include "Matrix.hpp"

namespace CFD::Types {

Matrix::Matrix() : shape{0,0} {}

Matrix::Matrix(size_t n) : shape{n,n} {
    data.resize(n);
    for (size_t i = 0; i < n; i++) {
        data[i].resize(n,0);
        data[i][i] = 1;
    }
}

Matrix::Matrix(size_t i, size_t j) : shape{i,j} {
    data.resize(i);
    for (size_t i_ = 0; i_ < i; i_++) {
        data[i_].resize(j,0);
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    data = other.data;
    shape = other.shape;
    return *this;
}

Value& Matrix::at(size_t i, size_t j) {
    return data[i][j];
}

Value Matrix::at(size_t i, size_t j) const {
    return data[i][j];
}

// Matrix Matrix::operator+(const Matrix& other) const {
//     Matrix tmp(shape[0], shape[1]);
//     if (other.shape[0] == shape[0] && other.shape[1] == shape[1]) {
//         for (size_t i = 0; i < shape[0]; i++) {
//             for (size_t j = 0; j < shape[1]; j++) {
//                 tmp.at(i,j) = data[i][j] + other.data[i][j];
//             }
//         }
//     } else if (other.shape[0] == 1 && shape[1] == 1) {
//         for (size_t i = 0; i < shape[0]; i++) {
//             for (size_t j = 0; j < shape[1]; j++) {
//                 tmp.at(i,j) = data[i][j] + other.data[0][0];
//             }
//         }
//     } else {
//         // Invalid
//     }
//     return tmp;
// }
Matrix identity(size_t n) {
    return diag(n,1);
}
Matrix diag(size_t n, Value val) {
    Matrix tmp{n};
    for (size_t i = 0; i < n; i++) {
        tmp.at(i,i) = val;
    }
    return tmp;
}

Matrix ones(size_t n) {
    return fill(n,n,1);
}

Matrix fill(size_t n_rows, size_t n_cols, Value val) {
    Matrix tmp{n_rows,n_cols};
    for (size_t i = 0; i < n_rows; i++) {
        for (size_t j = 0; j < n_cols; j++) {
            tmp.at(i,j) = val;
        }
    }
    return tmp;
}

Matrix operator+(const Matrix& mat1, const Matrix& mat2) {
    Matrix tmp{mat1.shape[0], mat1.shape[1]};
    for (size_t i = 0; i < tmp.shape[0]; i++) {
        for (size_t j = 0; j < tmp.shape[1]; j++) {
            tmp.at(i,j) = mat1.at(i,j) + mat2.at(i,j);
        }
    }

    return tmp;
}
Matrix Matrix::operator-(const Matrix& other) const {
    Matrix mat(1);
    return mat;
}
Matrix Matrix::operator*(const Matrix& other) const {
    assert(shape[1] == other.shape[0]);
    Matrix res(shape[0], other.shape[1]);
    for (size_t i = 0; i < shape[0]; i++) {
        for (size_t j = 0; j < other.shape[1]; j++) {
            // i,j element of out matrix
            for (size_t l = 0; l < shape[1]; l++) {
                res.at(i,j) = res.at(i,j) + (at(i,l)*other.at(l,j));
            }
        }
    }
    return res;
}
Matrix operator/(const Matrix& mat1, const Matrix& mat2) {

    if (mat1.shape[0] == 1 && mat1.shape[1] == 1) {

    } else if (mat2.shape[0] == 1 && mat2.shape[1] == 1) {
        Matrix tmp{mat1.shape[0], mat1.shape[1]};
        for (size_t i = 0; i < mat1.shape[0]; i++) {
            for (size_t j = 0; j < mat1.shape[1]; j++) {
                tmp.at(i,j) = tmp.at(i,j) / mat2.at(0,0);
            }
        }
        return tmp;
    }
    Matrix tmp{0};
    return tmp;
}

std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
    os << "Matrix of shape (" << mat.shape[0] << ", " << mat.shape[1] << "):\n";
    for (size_t i = 0; i < mat.shape[0]; i++) {
        for (size_t j = 0; j < mat.shape[1]-1; j++) {
            os << mat.at(i,j) << ", ";
        }
        os << mat.at(i,mat.shape[1]-1) << "\n";
    }
    return os;
}

}