#include<bits/stdc++.h>
using namespace std;
class Queue {
public:
    int arr[5000]={0};
    int indexToAdd=0;
    int indexToPop=0;
    Queue() {
        // Implement the Constructor
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return indexToPop==indexToAdd;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr[indexToAdd++]=data;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(indexToPop==indexToAdd)
            return -1;
        
        return arr[indexToPop++];
    }

    int front() {
        // Implement the front() function
        if(indexToPop==indexToAdd)
            return -1;
        
        return arr[indexToPop];
    }
};