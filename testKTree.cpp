#include "ktree.hpp"
#include "Mesh.hpp"
#include "Matrix.hpp"

using namespace CFD;

int main() {
    Util::Matrix<double> mat(2,2);
    mat.at(0,0) = 2;
    mat.at(1,1) = 5;

    Util::Matrix<double>::DiagIterator iter = mat.diagBegin();
    std::cout << *iter << "\n";
    iter++;
    std::cout << *iter << "\n";

    return 0;
}