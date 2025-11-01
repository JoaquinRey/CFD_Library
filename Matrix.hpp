#pragma once
#include <vector>
#include <cstdint>
#include <cassert>
#include <iterator>
#include <cstddef>

namespace CFD::Util {

template <typename Type>
class Matrix {

private:
    std::vector<std::vector<Type>> data;
    size_t numRows;
    size_t numCols;

public:
    struct RowIterator;
    struct ColIterator;
    struct DiagIterator;
    struct Iterator1D;
    struct Iterator;
    Iterator begin() { return Iterator(&(data[0][0]));}
    DiagIterator diagBegin() { return DiagIterator(&(data[0]),0); }

    Matrix() {}
    Matrix(size_t num_rows, size_t num_cols ) : numRows(num_rows), numCols(num_cols) {
        data.resize(num_cols, std::vector<Type>(num_rows, 0));
    }
    Matrix(Matrix& other) {}
    Matrix& operator=(Matrix& other);
    Matrix row(size_t r);
    Matrix col(size_t c);
    Type& at(size_t i, size_t j) {return (data[i][j]); }
    Type at(size_t i, size_t j) const {return data[i][j]; }
    Matrix transpose();

    template <typename OtherType>
    Matrix<OtherType> operator+(const Matrix<OtherType>& other) {
        return other;
    }
    template <typename OtherType>
    Matrix<OtherType> operator-(const Matrix<OtherType>& other) {
        return other;
    }
    template <typename OtherType>
    Matrix<OtherType>* operator*(const Matrix<OtherType>& other) {
        return other;
    }
    template <typename OtherType>
    Matrix<OtherType> operator/(const Matrix<OtherType>& other) {
        return other;
    }

    template<typename Type1, typename Type2>
    friend Matrix cross(const Matrix<Type1>& m1, const Matrix<Type2>& m2);
};

template <typename Type>
class Field : public Matrix<Type> {

};

template <typename Type>
struct Matrix<Type>::Iterator {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = Type;
    using pointer = Type*;
    using reference = Type&;

    Iterator(pointer ptr) : m_ptr(ptr) {}

    reference operator*() const { return *m_ptr; }
    pointer operator->() { return m_ptr; }
    friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };

    virtual Iterator& operator++() = 0;
    virtual Iterator operator++(int) = 0;
private:
    pointer m_ptr;
};

template <typename Type>
struct Matrix<Type>::DiagIterator {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using col_ptr = std::vector<Type>*;
    using value_type = Type;
    using pointer = Type*;
    using reference = Type&;

    DiagIterator(col_ptr ptr, size_t indx) : m_ptr(ptr), idx(indx) {}

    reference operator*() const { return (*m_ptr)[idx]; }
    pointer operator->() { return (*m_ptr)[idx]; }
    DiagIterator& operator++() { m_ptr++; idx++; return *this; }
    DiagIterator operator++(int) { DiagIterator tmp = *this; ++(*this); return tmp; }
    friend bool operator== (const DiagIterator& a, const DiagIterator& b) { return a.m_ptr == b.m_ptr; };
    friend bool operator!= (const DiagIterator& a, const DiagIterator& b) { return a.m_ptr != b.m_ptr; };

private:
    col_ptr m_ptr;
    size_t idx;
};

}