#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int temp;
        while(!q1.empty())
        {   
            temp = q1.front();
            q1.pop();
            if(!q1.empty())
            q2.push(temp);  
        }
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        return temp;
    }
    
    int top() {
        return q1.back();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */