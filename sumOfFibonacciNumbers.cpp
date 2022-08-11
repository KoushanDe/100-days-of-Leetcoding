// int minmNum(vector<long>& fibos,int ind,int target,vector<vector<long>>& dp)
// {
//     if(target==0)
//     return 0;
//     if(ind==fibos.size())
//     return 1e9;
    
//     if(dp[ind][target]!=-1) return dp[ind][target];
    
//     long notake = minmNum(fibos,ind+1,target,dp);
//     long take = 1e9;
//     if(fibos[ind]<=target)
//     take = 1+minmNum(fibos,ind,target-fibos[ind],dp);
    
//     return dp[ind][target]=min(take,notake);
// }
int Solution::fibsum(int A) {
    vector<long> fibos;
    fibos.push_back(1);
    fibos.push_back(1);
    
    for(int i=2;fibos.back()<A;i++)
    {
        fibos.push_back(fibos[i-1]+fibos[i-2]);
    }
    int count=0;
    for(int i=fibos.size()-1;i>=0;i--)
    {
        if(fibos[i]<=A)
        {
            A-=fibos[i];
            count++;
        }
    }
    
    return count;
}
