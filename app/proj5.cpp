//proj5.cpp

#include <iostream>
#include <sstream>
#include <string>
#include "proj5.hpp"
#include <iterator>

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

//
//template<class Iter>
//void mergeSort(Iter beg, Iter end)
//{
//    auto len = std::distance(beg,end);
//    if (len < 2)
//        return;
//
//    Iter mid = std::next(beg,len/2);
//    mergeSort(beg, mid);
//    mergeSort(mid, end);
//    std::inplace_merge(beg, mid, end);
//}

void mergeSort(std::vector<std::string> &vec, std::vector<std::string> &left, std::vector<std::string> &right){
    int leftSize = left.size();
    int rightSize = right.size();
    int i = 0, j = 0, k = 0;

    while (j < leftSize && k < rightSize)
    {
        if (left[j] < right[k]) {
            vec[i] = left[j];
            j++;
        }
        else {
            vec[i] = right[k];
            k++;
        }
        i++;
    }
    while (j < leftSize) {
        vec[i] = left[j];
        j++; i++;
    }
    while (k < rightSize) {
        vec[i] = right[k];
        k++; i++;
    }
}

void doSomeSort(std::vector<std::string> &vec) {
    // std::sort(vec.begin(), vec.end());   //  <---- stub stub stub
    if (vec.size() > 1) {

        int mid = vec.size() / 2;
        std::vector<std::string> left;
        std::vector<std::string> right;

        for (int i = 0; i < mid; i++)
            left.push_back(vec[i]);
        for (int i = 0; i < (vec.size()) - mid; i++)
            right.push_back(vec[mid + i]);

        doSomeSort(left);
        doSomeSort(right);
        mergeSort(vec, left, right);

    }


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
