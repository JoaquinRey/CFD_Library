#pragma once
#include <list>
#include <memory>
#include <array>
#include <cassert>

namespace CFD::Utils {

/*
    Template base class for values defining operations between them
    Used for vectors, scalars, matrices, etc
*/
class Value {
protected:
    size_t dimensions;
    std::list<size_t> dimens;

    Value(size_t dim) : dimensions(dim) {}
public:
    virtual ~Value() = default;
    virtual double get(std::list<int> indices={}) const = 0;
    virtual std::unique_ptr<Value> operator+(const Value& other) = 0;
    virtual std::unique_ptr<Value> operator-(const Value& other) = 0;
    virtual std::unique_ptr<Value> operator*(const Value& other) = 0;
    virtual std::unique_ptr<Value> operator/(const Value& other) = 0;
};

class Scalar : public Value {
private:
    double value;
public:
    Scalar(double val) : value(val), Value(1) {}
    double get(std::list<int> indices={}) const {
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

class Vector : public Value {

private:
    std::array<double,3> data;

public:
    Vector(double x, double y, double z) : Value(2), data{x,y,z} {}
    double get(std::list<int> indices={}) const {
        assert(indices.size() == dimensions);
        return data[indices.front()];
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
};

}