#pragma once
#include "BaseValue.hpp"

namespace CFD::Types {

class Scalar : public Value<double> {
private:
    double value;
public:
    Scalar(double val) : value(val), Value(0) {}
    double get(std::vector<int> indices={}) const {
        return value;
    };
    std::unique_ptr<Value> operator+(const Value& other) {
        Value* tmp = new Scalar(value + other.get());
        return std::unique_ptr<Value>(tmp);
    };
    std::unique_ptr<Value> operator-(const Value& other) {
        Value* tmp = new Scalar(value - other.get());
        return std::unique_ptr<Value>(tmp);
    };
    std::unique_ptr<Value> operator*(const Value& other) {
        Value* tmp = new Scalar(value * other.get());
        return std::unique_ptr<Value>(tmp);
    };
    std::unique_ptr<Value> operator/(const Value& other) {
        Value* tmp = new Scalar(value / other.get());
        return std::unique_ptr<Value>(tmp);
    };
};


}