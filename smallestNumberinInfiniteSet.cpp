class SmallestInfiniteSet {
public:
    vector<int> nums = vector<int>(1002,1);
    int index;
    SmallestInfiniteSet() {
        index=1;
    }
    
    int popSmallest() {
        int smol = index;
        nums[index]=0;
        while(nums[index]!=1)
        {
            index++;
        }
        return smol;
    }
    
    void addBack(int num) {
        nums[num]=1;
        index=min(index,num);
    }
};

//PRIORITY QUEUE SOLUTION ALSO POSSIBLE

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */