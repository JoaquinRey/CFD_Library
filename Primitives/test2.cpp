#include <array>
#include <variant>
#include <iostream>

using namespace std;

struct Scalar {
    double val;

    Scalar(double v) : val(v) {}
    double get(size_t i=0) const {
        return val;
    }
};
ostream& operator<<(ostream& os, const Scalar& v) {
    os << "Scalar: " << v.val << "\n";
    return os;
}

struct Vec {
    array<double,3> vals;

    Vec(double x, double y, double z) : vals{x,y,z} {}
    double get(size_t i=0) const {
        return vals[i];
    }
};
ostream& operator<<(ostream& os, const Vec& v) {
    os << "Vector: (" << v.vals[0] << ", " << v.vals[1] << ", " << v.vals[2] << ")\n";
    return os;
}

using Value = variant<Scalar,Vec>;

Value operator+(const Value& lhs, const Value& rhs) {
    return visit([](auto&& x, auto&& y) -> Value {
        using X = decay_t<decltype(x)>;
        using Y = decay_t<decltype(y)>;
        if constexpr (is_same_v<X,Vec> || is_same_v<Y,Vec>) {
            return Value{Vec(x.get(0)+y.get(0),x.get(1)+y.get(1),x.get(2)+y.get(2))};
        } else {
            return Value{Scalar(x.get()+y.get())};
        }
    }, lhs, rhs);
}

ostream& operator<<(ostream& os, const Value& v) {
    visit([&](auto&& arg) {
        os << arg;
    }, v);
    return os;
}

int main() {
    Value a = Scalar(2);
    Value v1 = Vec(1,2,3);
    Value res = v1 + a;
    cout << res;
    Value b = Scalar(3);
    Value c = a + b;

    visit([](auto&& v) {
        cout << v;
    }, c);
    return 0;
}