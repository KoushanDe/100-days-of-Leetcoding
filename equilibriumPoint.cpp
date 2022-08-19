class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int,int> freq;
        int n = nums.size();
        
        int low = nums[0];
        int high = nums[n-1];
        
        for(auto &it:nums)
            freq[it]++;
        
        int flag=0,count=0,maxm;
        
        while(true)
        {   
            count=0;
            flag=0;
            maxm=INT_MIN;
            for(int i=low;i<=high;i++)
            {   
                if(freq[i]>0&&flag==0)
                {
                    if(freq[i]==1){
                        flag=1;
                    }
                    else
                    {   
                        maxm = max(maxm,freq[i]);
                        flag=2;
                    }
                    freq[i]--;
                    count++;
                }
                else if(flag==1)
                {
                    if(freq[i]==0)
                    {
                        if(count<3)
                            return false;
                        else
                            break;
                    }
                    else if(freq[i]>1)
                    {
                        maxm=max(maxm,freq[i]);
                        flag=2;
                    }
                    
                    freq[i]--;
                    count++;
                }
                else if(flag==2)
                {
                    if(freq[i]<maxm)
                    {
                        if(count<3)
                            return false;
                        else
                            break;
                    }
                    maxm=max(maxm,freq[i]);
                    freq[i]--;
                    count++;
                }
            }
            
            if(flag==0)
                break;
            if(count<3)
                return false;
        }
        
        return true;
    }
};