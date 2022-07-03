// Stack class.
class Stack {
    
public:
    int arr[1000]={0};
    int cap=0;
    int indexToAdd=0;
    Stack(int capacity) {
        cap = capacity;
    }

    void push(int num) {
        arr[indexToAdd]=num;
        indexToAdd++;
    }

    int pop() {
        indexToAdd--;
        if(indexToAdd<0)
        {    indexToAdd=0;
            return -1;
        }
        return arr[indexToAdd];
    }
    
    int top() {
        if(indexToAdd==0)return -1;
        return arr[indexToAdd-1];
    }
    
    int isEmpty() {
        return indexToAdd==0;
    }
    
    int isFull() {
        return indexToAdd==cap;
    }
    
};