#pragma once
#include "BaseValue.hpp"
#include "../Scalar.hpp"
#include "../Vector.hpp"
#include <cassert>

namespace CFD::Types {

/*
    2 by 2 matrix
*/
class Matrix {

private:
    std::array<size_t,2> dimensions;
    std::vector<std::vector<Value>> data;
public:
    Matrix() {}
    Matrix(size_t width, size_t height) {
        data.resize(height);
        for (size_t i = 0; i < height; i++) {
            data[i].resize(width);
        }
    }
    Matrix(std::vector<std::vector<Value>> matrix) : data(matrix) {}

    double get(std::vector<int> indices={}) const {

    }
    Matrix T() const {
        std::vector<std::vector<Value>> tmpData;
        tmpData.resize(dimensions[1]);
        for (size_t i = 0; i < dimensions[1]; i++) {
            tmpData[i].resize(dimensions[0]);
            for (size_t j = 0; j < dimensions[0]; i++) {
                tmpData[i][j] = data[j][i];
            }
        }
        Matrix tmp(tmpData);
        return tmp;
    }
    std::vector<Value> row(size_t idx);
    std::vector<Value> col(size_t idx);
    Matrix operator+(const Matrix& other);
    Matrix operator-(const Matrix& other);
    Matrix operator*(const Matrix& other);
    Matrix operator/(const Matrix& other);

    friend Matrix dot(const Matrix& m1, const Matrix& m2);
    friend Matrix cross(const Matrix& m1, const Matrix& m2);
};

}