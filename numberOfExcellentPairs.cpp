class Solution {
public:
    
    long long countExcellentPairs(vector<int>& nums, int k) {
        vector<set<int>> setbit(33);
        long long ans = 0;
        
        for(int num:nums)
        {   
            int bit=0;
            for(int i=0;i<32;i++)
            {
                if(num&1<<i)
                    bit++;
            }
            //cout<<bit<<endl;
            setbit[bit].insert(num);
        }
        
        for(int bit=1;bit<=32;bit++)
        {
            if(2*bit>=k)
            {
                int size = setbit[bit].size();
                ans = ans + size*size;
            }
            //cout<<ans<<"equal"<<endl;
        }
        
        int i=1,j=32;
        
        while(i<j)
        {
            if(i+j>=k)
            {   
                for(int l=i;l<j;l++)
                {
                    ans = ans + setbit[l].size()*setbit[j].size()*2;
                //cout<<ans<<endl;   
                }
                
                j--;
            }
            else
                i++;
        }
        
        return ans;
    }
};