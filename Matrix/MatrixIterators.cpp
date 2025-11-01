#include "Matrix.hpp"
#include <iterator>
#include <cstddef>

namespace CFD::Types {

struct Matrix::Iterator1D {
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using arr_ptr = std::vector<Value>*;
    using value_type = Value;
    using pointer = Value*;
    using reference = Value&;

    Iterator1D(arr_ptr ptr, size_t index) : a_ptr(ptr), idx(index) {
        column_vector = a_ptr->size() == 1;
    }

    reference operator*() const { return (*a_ptr)[idx]; }
    Iterator1D& operator++() {
        if (column_vector) {
            a_ptr++;
        } else {
            idx++;
        }
        return *this;
    }

private:
    bool column_vector;
    arr_ptr a_ptr;
    size_t idx;
};

}