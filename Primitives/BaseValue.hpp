#pragma once
#include <list>
#include <memory>
#include <array>
#include <cassert>
#include <vector>

namespace CFD::Types {

/*
    Template base class for values defining operations between them
    Used for vectors, scalars, matrices, etc
*/
class Value {
protected:
    size_t dimensions;
    std::vector<size_t> data_shape;

    Value(size_t dim) : dimensions(dim), data_shape(std::vector<size_t>(dim,1)) {}
    Value(std::vector<size_t> shape) : dimensions(shape.size()), data_shape(shape) {}

public:
    size_t get_dimensions() const { return dimensions; }
    std::vector<size_t> get_shape() const { return data_shape; }

    virtual ~Value() = default;
    virtual double get(std::vector<int> indices={}) const = 0;
    virtual std::unique_ptr<Value> operator+(const Value& other) const = 0;
    virtual std::unique_ptr<Value> operator-(const Value& other) const = 0;
    virtual std::unique_ptr<Value> operator*(const Value& other) const = 0;
    virtual std::unique_ptr<Value> operator/(const Value& other) const = 0;
};

}