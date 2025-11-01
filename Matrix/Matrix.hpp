#pragma once
#include <vector>
#include <cstdint>
#include <cassert>
#include <iterator>
#include <cstddef>
#include <iostream>
#include "Value.hpp"

namespace CFD::Types {

using Slice = std::vector<size_t*>;

/*
    Base type for a 2d matrix
*/
class Matrix {

private:
    std::vector<std::vector<Value>> data;
    std::array<size_t,2> shape;

public:
    struct RowIterator;
    struct ColIterator;
    struct DiagIterator;
    struct Iterator1D;
    //struct Slice;

    Matrix();
    Matrix(size_t n);
    Matrix(size_t i, size_t j);
    Matrix(std::vector<std::vector<Value> >& vec);

    Matrix& operator=(const Matrix& other);

    Value at(size_t i, size_t j) const;
    Value& at(size_t i, size_t j);

    std::array<size_t,2> get_shape() const;

    friend Matrix operator+(const Matrix& mat1, const Matrix& mat2);
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    friend Matrix operator/(const Matrix& mat1, const Matrix& mat2);

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat);
};

class Field : public Matrix {
public:
    Value at(size_t i) const;
    Value at(size_t i);
};

Matrix identity(size_t n);
Matrix diag(size_t n, Value val);
Matrix ones(size_t n);
Matrix fill(size_t n_rows, size_t n_cols, Value val);

}