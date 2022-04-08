#include<bits/stdc++.h>
#include<iostream>

using namespace std;
class KthLargest {
public:
    int k;
    vector<int> nums;
    KthLargest(int k, vector<int>& nums) {
        this->nums=nums;
        this->k = k;
        sort(this->nums.begin(),this->nums.end(), greater<int>());
    }
    
    int add(int val) {
        int size = nums.size();
        if(size==0)
        {
            nums.push_back(val);
            return val;
        }
        
        for(int i=0;i<size;i++)
        {
            if(val>nums[i])
            {
                nums.emplace(nums.begin()+i,val);
                break;
            }
        }
        if(nums.size()==size)
            nums.push_back(val);
        return nums[k-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
