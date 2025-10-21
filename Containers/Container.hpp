#pragma once
#include <vector>

namespace CFD {

struct data_t {
    double x;
    double y;
};

struct Range {
    double minVal;
    double maxVal;
};

template <typename Type>
class Container {

private:
    std::vector<Type> data;
    size_t max_bucket_size;
    size_t num_buckets;
    size_t num_elements;

    struct Bucket {
        double minVal;
        double maxVal;
        Bucket* left;
        Bucket* right;
        size_t max_size;
        std::vector<Type> data;
    };
    Bucket* root;


public:

    void insert(Type val) {

    }

};




}