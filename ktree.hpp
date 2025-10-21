#pragma once
#include <cstdint>
#include <vector>
#include <iostream>

template <typename Type, int dim, class Comp>
class KTree {

private:
    std::vector<Type> vals;
    struct Node {
        Type val;
        Node* left;
        Node* right;
        size_t idx;
        uint32_t layer;
    };
    Node* root;

public:
    KTree() : root(nullptr) {}
    int push(const Type& val) {
        if (root == nullptr) {
            vals.push_back(val);
            root = new Node({vals.back(), nullptr, nullptr, 0, 0});
            return vals.size()-1;
        }
        Node* curr = root;
        uint32_t curr_layer = 0;
        while (curr != nullptr) {
            if (curr->val == val) {
                return curr->idx;
            }
            if (Comp{}(curr->val, val, curr_layer)) {
                if (curr->left == nullptr) {
                    vals.push_back(val);
                    curr->left = new Node({vals.back(), nullptr, nullptr, vals.size()-1, curr_layer});
                    return vals.size()-1;
                }
                curr = curr->left;
            } else {
                if (curr->right == nullptr) {
                    vals.push_back(val);
                    curr->right = new Node({vals.back(), nullptr, nullptr, vals.size()-1, curr_layer});
                    return vals.size()-1;
                }
                curr = curr->right;
            }
            curr_layer = (curr_layer+1) % dim;
        }
        return -1;
    }

    size_t size() {
        return vals.size();
    }

    void printData() {
        std::cout << "Container data(" << vals.size() << " items):\n"; 
        for (Type curr : vals) {
            std::cout << curr.x << ", " << curr.y << ", " << curr.z << "\n";
        }
    }

    Type operator[](int idx) const {return vals[idx];};
    Type& operator[](int idx) {return vals[idx];}

};