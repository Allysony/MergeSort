//proj5.cpp

#include <iostream>
#include <sstream>
#include <string>
#include "proj5.hpp"

bool isMinHeap(std::string s) {
    int heapHeight = (s.length() - 2) / 2;

    for (int i = 0; i <= heapHeight; i++) {
        int leftChild = (int) s[2 * i + 1];
        int rightChild = (int) s[2 * i + 2];
        int parent = (int) s[i];

        // left child is not greater
        if (parent > leftChild) {
            return false;
        }
        // if there is a right child
        if (2 * i + 2 < s.length()) {
            // if right child is not greater
            if (parent > rightChild) {
                return false;
            }
        }
    }
    return true;
}


void doSomeSort(std::vector<std::string> &vec) {
    std::sort(vec.begin(), vec.end());

}


std::vector<std::string> findHeaps(std::istream &in) {
    std::vector<std::string> foo;
    std::string tmp;
    while (in >> tmp) {
        if(isMinHeap(tmp)){

            foo.push_back(tmp);
        }
    }
    doSomeSort(foo);
    return foo;
}
