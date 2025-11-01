#include "Matrix.hpp"
#include "Value.hpp"
#include <iostream>

using namespace CFD::Types;

int main() {
    Matrix vel_field = fill(10,1,2);
    Matrix A = identity(10);
    Matrix b = A*vel_field;
    std::cout << b << "\n";
    return 0;
}