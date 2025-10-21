#include "MatrixTypes.hpp"
#include <iostream>

using namespace CFD::Utils;

int main() {
    Scalar* tmp = new Scalar(5);
    Scalar* tmp2 = new Scalar(7);
    std::unique_ptr<Value> res = (*tmp) + (*tmp2);
    std::cout << res->get() << "\n";
    return 0;
}