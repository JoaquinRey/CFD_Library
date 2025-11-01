#include "Matrix.hpp"

namespace CFD::Types {

Matrix Matrix::operator+(const Matrix& other) {

}
Matrix Matrix::operator-(const Matrix& other) {

}
Matrix Matrix::operator*(const Matrix& other) {

}
Matrix Matrix::operator/(const Matrix& other) {

}

Matrix dot(const Matrix& m1, const Matrix& m2) {
    assert(m1.dimensions[1] == m2.dimensions[0]);
    for (size_t h = 0; h < m1.dimensions[0]; h++) {
        for (size_t w = 0; w < m2.dimensions[1]; w++) {
            std::unique_ptr<Value> currSum = std::make_unique<Value>(Scalar(0));
            for (size_t i = 0; i < m1.dimensions[1]; i++) {
                std::unique_ptr<Value> ptr = (m1.data[h][i] * m1.data[i][w]);
                
            }
        }
    }
}
Matrix cross(const Matrix& m1, const Matrix& m2) {

}


}