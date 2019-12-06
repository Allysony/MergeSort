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


/**
 *
 * @param vec
 * @param left
 * @param right
 *
 *  given sorted vectors right and left, return sorted vector containing elements of right and left
 *
 */
void merge(std::vector<std::string> &vec, std::vector<std::string> &left, std::vector<std::string> &right) {
    int leftSize = left.size();
    int rightSize = right.size();

    // Loop Counters
    int vecCounter = 0;
    int leftCounter = 0;
    int rightCounter = 0;

    while (leftCounter < leftSize and rightCounter < rightSize) {
        // if left curr value is smaller than right curr value
        if (left[leftCounter] < right[rightCounter]) {
            // copy left current to vec
            vec[vecCounter] = left[leftCounter];

            leftCounter++;
        }
            // if right curr value is smaller than left curr value
        else {
            // copy right current to vec
            vec[vecCounter] = right[rightCounter];
            rightCounter++;
        }
        vecCounter++;
    }
    while (leftCounter < leftSize) {
        // copy the remaining elements of left to vec
        vec[vecCounter] = left[leftCounter];
        leftCounter++;
        vecCounter++;
    }
    while (rightCounter < rightSize) {
        // copy the remaining elements of right to vec
        vec[vecCounter] = right[rightCounter];
        rightCounter++;
        vecCounter++;
    }




    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

/**
 *
 * @param vec
 *
 * utilizes divide and conquer pattern
 *
 * if vec is smaller than 2 then do not sort, if greater then recursively split vec smaller
 *
 * then take sub vecs (rights and lefts) and merge them into vec
 *
 */
void doSomeSort(std::vector<std::string> &vec) {

    // **************----------------------------DIVIDE-----------------------**************

    // if vec has zero or one element, do nothing


    //if vec has at least 2 elements
    if (vec.size() > 1) {

        // divide vec in about half into left and right sub vecs
        int mid = (int) vec.size() / 2;
        std::vector<std::string> left;
        std::vector<std::string> right;

        for (int i = 0; i < mid; i++)
            left.push_back(vec[i]);
        for (int i = 0; i < (vec.size()) - mid; i++)
            right.push_back(vec[mid + i]);


        // **********----------------------------RECUR-----------------------**************
        doSomeSort(left);
        doSomeSort(right);


        // **********----------------------------CONQUER-----------------------**************
        merge(vec, left, right);

    }


}


std::vector<std::string> findHeaps(std::istream &in) {
    std::vector<std::string> foo;
    std::string tmp;
    while (in >> tmp) {
        if (isMinHeap(tmp)) {
            foo.push_back(tmp);
        }
    }
    doSomeSort(foo);
    return foo;
}
