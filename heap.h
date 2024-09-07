// heap.h
// Binary heap tree header file for CS 24 lab
// Diba Mirza

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>

class Heap{

 public:

    void printIt();
    void push(int value);     // insert value; //duplicates are allowed
    void pop(); // delete the min element 
    int top();
    bool empty();
    void swap(int indexA, int indexB);
    int findIndex(int value);
    int parentIndex(int index);
    
 private:
    std::vector<int> vdata; //store the binary heap tree as a dynamic array
};

#endif