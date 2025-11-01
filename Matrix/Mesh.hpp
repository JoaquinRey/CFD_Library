#pragma once
#include <cstdint>
#include <array>
#include <vector>
#include <vector>
#include "Value.hpp"
#include "Matrix.hpp"

namespace CFD::Types {

struct Face {
    size_t neighbor;
    double distance;
    Value normal;
};

struct Cell {
    double volume;
    Value center;
    std::vector<Face> faces;
};


}