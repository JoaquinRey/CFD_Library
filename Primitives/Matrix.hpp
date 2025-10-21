#pragma once
#include "BaseValue.hpp"
#include <cassert>

namespace CFD::Types {

/*
    2 by 2 matrix
*/
template <typename Type>
class Matrix : public Value<Type> {

private:
    std::vector<std::vector<double>> data;
public:
    Matrix() : Value({0,0}) {}

    Type get(std::vector<int> indices={}) const {
        assert(indices.size() == dimensions);
    }
    std::unique_ptr<Value> operator+(const Value& other);
    std::unique_ptr<Value> operator-(const Value& other);
    std::unique_ptr<Value> operator*(const Value& other);
    std::unique_ptr<Value> operator/(const Value& other);
};

}