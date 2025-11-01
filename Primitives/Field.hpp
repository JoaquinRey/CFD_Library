#pragma once
#include "BaseValue.hpp"
#include <vector>

namespace CFD::Primitive {

template <typename Type>
class Field : public Value<Type> {

private:
    std::vector<Type> data;

public:
    Field() : Value({0}) {}

    Type get(std::vector<int> indices={}) const {
        assert(indices.size() == dimensions);
    }
    std::unique_ptr<Value> operator+(const Value& other);
    std::unique_ptr<Value> operator-(const Value& other);
    std::unique_ptr<Value> operator*(const Value& other);
    std::unique_ptr<Value> operator/(const Value& other);
};

    
}