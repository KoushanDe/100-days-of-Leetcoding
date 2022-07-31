class SGTree {
  public:  
    vector<int> seg;
    
    void init(int n)
    {
        seg.resize(4*n+1);
    }
    
    void build(int ind, int low, int high, vector<int>& arr)
    {
        if(low==high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low+high)/2;
            
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
    
    int query(int ind, int l, int r, int low, int high)
    {
        //no overlap
        //low>r high<l
        if(low>r || high<l) return 0;
        
        //complete overlap
        if(l<=low&&high<=r)
            return seg[ind];
        
        int mid = (low+high)/2;

        int q1 = query(2*ind+1,l,r,low,mid);
        int q2 = query(2*ind+2,l,r,mid+1,high);
        return q1+q2;
    }
    
    void update(int ind,int low,int high,int i,int val)
    {
        if(low==high)
        {
            seg[ind]=val;
            return;
        }
        
        int mid=(low+high)/2;
        if(i<=mid)
            update(2*ind+1,low,mid,i,val);
        else
            update(2*ind+2,mid+1,high,i,val);
        
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
    }
};
class NumArray {
public:
    int n=0;
    SGTree S;
    NumArray(vector<int>& nums) {
        n = nums.size();
        S.init(n);
        S.build(0,0,n-1,nums);
    }
    
    void update(int index, int val) {
        S.update(0,0,n-1,index,val);
    }
    
    int sumRange(int left, int right) {
        return S.query(0,left,right,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */