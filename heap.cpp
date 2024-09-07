// heap.cpp
// Diba Mirza

#include "heap.h"
#include <iostream>
using namespace std;

void Heap::printIt() {
  for (int i = 0; i < vdata.size(); i++)
      cout << vdata[i] << " ";
}

//finds the index of the given value
int Heap::findIndex(int value) {
  for (int i = 0; i < vdata.size(); i++)
    if (vdata[i] == value)
      return i;
  return -1;
}

//finds the parent index of the node with given index
int Heap::parentIndex(int index) {
  if (vdata.size() > 1) 
      return (index-1)/2;
  return -1;
}


// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value) {
  if(vdata.size() == 0)
    vdata.push_back(value);
  else {
    vdata.push_back(value);
    int n = parentIndex(findIndex(value));
    while ((n != -1) && ((n <= vdata.size()-1) && (value < vdata[n]))) {
      swap(findIndex(value), n);
      n = parentIndex(findIndex(value));
    }
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.size() == 0)
    return;
  else if (vdata.size() == 1) {
    //vdata.pop_back();
    // cout << "orig" << endl;
    // for (int i = 0; i < vdata.size(); i++)
    //   cout << vdata[i] << endl;
    vdata.clear();
    // cout << "new" << endl;
    // for (int i = 0; i < vdata.size(); i++)
    //   cout << vdata[i] << endl;
    // cout << "done" << endl; 
    // cout << "goodbyee" << vdata[0] << endl;
    return;
  }
  else {
    
    int valueIndex = 0;
    int swapIndex;
    int leftIndex = 2*valueIndex + 1;
    int rightIndex = 2*valueIndex + 2;
     
    if (vdata.size() > 2) {
      if (vdata[leftIndex] <= vdata[rightIndex]) {
        swapIndex = leftIndex;
      }
      else
        swapIndex = rightIndex;
    }
    else {
      swapIndex = -1;
      if (vdata[0] > vdata[1])
        swap(0,1);
      }


    swap(0, vdata.size()-1);
    vdata.pop_back();
  

    while ((swapIndex != -1) && (vdata[valueIndex] > vdata[swapIndex])) {
      swap(valueIndex, swapIndex);
      valueIndex = swapIndex;
      int leftIndex = 2*valueIndex + 1;
      int rightIndex = 2*valueIndex + 2;

      if ((leftIndex <= vdata.size()-1) && (rightIndex <= vdata.size()-1)) {
        if (vdata[leftIndex] <= vdata[rightIndex]) {
          swapIndex = leftIndex;
        }
        else
          swapIndex = rightIndex;
      }
      else if ((leftIndex <= vdata.size()-1) && !(rightIndex <= vdata.size()-1)) 
        swapIndex = leftIndex;
      else if (!(leftIndex <= vdata.size()-1) && (rightIndex <= vdata.size()-1)) 
        swapIndex = leftIndex;
      else  
        swapIndex = -1;
        //break;
    }
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if (!vdata.empty())
    return vdata[0];
  return 0;
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if (vdata.size() == 0)
    return true;
  return false;
}

void Heap::swap(int indexA, int indexB) {
  int temp = vdata[indexA];
  vdata[indexA] = vdata[indexB];
  vdata[indexB] = temp;
}  

// int main () {
//   Heap obj;
//   cout << "hello" << endl;
//   for (int i = 0; i < 51; i++) {
//     obj.push(i);
//   }
//   cout << "lets print" << endl;
//   obj.printIt();
//   cout << "done print" << endl;
//   for (int i = 0; i < 51; i++) {
//     obj.pop();
//     obj.printIt();
//     cout << "top: " << obj.top() << endl;
//   }
//   cout << "emptied heap" << endl;
// }



//   cout << "hello";
//   Heap obj;
//   obj.push(20);
//   cout << obj.top() << endl;
//   obj.push(5);
//   cout << obj.top() << endl;
//   obj.push(7);
//   cout << obj.top() << endl;
//   obj.push(1);
//   cout << obj.top() << endl;
//   obj.push(3); 
//   cout << obj.top() << endl;
//   obj.push(2);
//   cout << obj.top() << endl;
//   obj.pop();
//   cout << obj.top() << endl;
//   obj.pop();
//   cout << obj.top() << endl;
//   obj.pop();
//   cout << obj.top() << endl;
//   obj.pop();
//   cout << obj.top() << endl;
//   obj.pop();
//   cout << obj.top() << endl;
//   obj.pop();
//   cout << obj.top() << endl;


//   Heap obj2;
//   cout << obj2.empty();