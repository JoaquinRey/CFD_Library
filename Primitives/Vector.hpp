#pragma once
#include "BaseValue.hpp"

namespace CFD::Types {

class Vector : public Value<double> {
private:
    std::array<double,3> data;

public:
    Vector() : Value({0,0}) {}
    Vector(double x, double y, double z) : Value({3}), data{x,y,z} {}
    double get(std::vector<int> indices={}) const {
        return data[indices[0]];
    }
    double X() {
        return data[0];
    }
    double Y() {
        return data[0];
    }
    double Z() {
        return data[0];
    }
    std::unique_ptr<Value> operator+(const Value& other) {
        assert(other.get_dimensions() == 0 || other.get_dimensions() == get_dimensions());
        Value* tmp = new Vector(
            data[0]+other.get({0}),
            data[1]+other.get({1}),
            data[2]+other.get({2}));
        return std::unique_ptr<Value>(tmp);
    };
    std::unique_ptr<Value> operator-(const Value& other) {
        Value* tmp = new Vector();
        return std::unique_ptr<Value>(tmp);
    };
    std::unique_ptr<Value> operator*(const Value& other) {
        Value* tmp = new Vector();
        return std::unique_ptr<Value>(tmp);
    };
    std::unique_ptr<Value> operator/(const Value& other) {
        Value* tmp = new Vector();
        return std::unique_ptr<Value>(tmp);
    };
};

}