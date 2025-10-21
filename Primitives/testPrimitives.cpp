#include "BaseValue.hpp"
#include "Scalar.hpp"
#include "Vector.hpp"
#include <iostream>
#include <cassert>

using namespace CFD::Types;

int main() {
    Vector pos(1,2,3);
    Vector other(2,3,4);
    Scalar x(2);
    std::unique_ptr<Value<double>> res = pos + x;

    std::cout << res->get({0}) << "\n";
    return 0;
}