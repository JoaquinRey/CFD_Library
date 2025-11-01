#include "BaseValue.hpp"
#include "Scalar.hpp"
#include "Vector.hpp"
#include <iostream>
#include <cassert>
#include <variant>

using namespace CFD::Types;

using value_t = std::variant<double, Vector>;

int main() {
    Vector pos(1,2,3);
    Vector other(2,3,4);
    Scalar x(2);
    std::unique_ptr<Value> res = pos + x;

    std::cout << res->get({0}) << "\n";
    return 0;
}