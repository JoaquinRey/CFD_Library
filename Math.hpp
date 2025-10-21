#pragma once
#include <vector>

namespace CFD::Math {

template <typename Type>
class Matrix {

private:
    int width;
    int height;
    std::vector<std::vector<Type>> data;

public:
    Matrix(Type value);
    Matrix(int w, int h);
    Matrix(std::vector<std::vector>>&& initial_data);

    Matrix& operator=(const Type& val);


    Matrix<Type>& dot(const Matrix<Type>& other);
    Matrix<Type>& cross(const Matrix<Type>& other);

    Type operator[](int i, int j) const;
    Type& operator[](int i, int j);


};

template <typename Type>
class Scheme {
private:

public:
    virtual Matrix<Type> operator()() = 0;

};

template<typename Type>
Matrix<Type>& dot(const Matrix<Type>& m1, const Matrix<Type>& m2);

template<typename Type>
Matrix<Type>& cross(const Matrix<Type>& m1, const Matrix<Type>& m2);

}