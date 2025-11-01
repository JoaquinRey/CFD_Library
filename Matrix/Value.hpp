#pragma once
#include <array>
#include <variant>
#include <iostream>

namespace CFD::Types {

struct Scalar {
    double val;

    Scalar(double v) : val(v) {}
    double get(size_t i=0) const {
        return val;
    }
};
inline std::ostream& operator<<(std::ostream& os, const Scalar& v) {
    os << v.val;
    return os;
}

struct Vector {
    std::array<double,3> vals;

    Vector(double x, double y, double z) : vals{x,y,z} {}
    double get(size_t i=0) const {
        return vals[i];
    }
};
inline std::ostream& operator<<(std::ostream& os, const Vector& v) {
    os << "(" << v.vals[0] << ", " << v.vals[1] << ", " << v.vals[2] << ")";
    return os;
}

using Value = std::variant<Scalar,Vector>;

inline Value operator+(const Value& lhs, const Value& rhs) {
    return visit([](auto&& x, auto&& y) -> Value {
        using X = std::decay_t<decltype(x)>;
        using Y = std::decay_t<decltype(y)>;
        if constexpr (std::is_same_v<X,Vector> || std::is_same_v<Y,Vector>) {
            return Value{Vector(x.get(0)+y.get(0),x.get(1)+y.get(1),x.get(2)+y.get(2))};
        } else {
            return Value{Scalar(x.get()+y.get())};
        }
    }, lhs, rhs);
}
inline Value operator-(const Value& lhs, const Value& rhs) {
    return visit([](auto&& x, auto&& y) -> Value {
        using X = std::decay_t<decltype(x)>;
        using Y = std::decay_t<decltype(y)>;
        if constexpr (std::is_same_v<X,Vector> || std::is_same_v<Y,Vector>) {
            return Value{Vector(x.get(0)-y.get(0),x.get(1)-y.get(1),x.get(2)-y.get(2))};
        } else {
            return Value{Scalar(x.get()-y.get())};
        }
    }, lhs, rhs);
}
inline Value operator*(const Value& lhs, const Value& rhs) {
    return visit([](auto&& x, auto&& y) -> Value {
        using X = std::decay_t<decltype(x)>;
        using Y = std::decay_t<decltype(y)>;
        if constexpr (std::is_same_v<X,Vector> && std::is_same_v<Y,Vector>) {
            return Value{Scalar(x.get(0)*y.get(0) + x.get(1)*y.get(1) + x.get(2)*y.get(2))};
        } else if constexpr (std::is_same_v<X,Vector> || std::is_same_v<Y,Vector>) {
            return Value{Vector(x.get(0)*y.get(0),x.get(1)*y.get(1),x.get(2)*y.get(2))};
        } else {
            return Value{Scalar(x.get()*y.get())};
        }
    }, lhs, rhs);
}
inline Value operator/(const Value& lhs, const Value& rhs);

inline std::ostream& operator<<(std::ostream& os, const Value& v) {
    visit([&](auto&& arg) {
        os << arg;
    }, v);
    return os;
}

}