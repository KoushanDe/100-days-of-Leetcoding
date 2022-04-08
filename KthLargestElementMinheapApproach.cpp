#include<bits/stdc++.h>
#include<iostream>

using namespace std;

class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;
    KthLargest(int k, vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            heap.push(nums[i]);
            if(heap.size()>k)
                heap.pop();
        }
        this->k = k;
    }
    
    int add(int val) {
        int size = heap.size();
        if(size==0)
        {
            heap.push(val);
            return val;
        }
        heap.push(val);
        if(heap.size()>k)
            heap.pop();
        
        return heap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
