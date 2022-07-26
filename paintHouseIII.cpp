class Solution {
public:
    /**MEMOISATION FASTER**
    int func(int ind,vector<int>& houses, vector<vector<int>>& cost, int neighbour,int target, int lcolor,vector<vector<vector<int>>>& dp)
    {   
        //cout<<"called"<<endl;
        if(neighbour>target)
            return 1e9;
        if(neighbour==target&&ind==houses.size())
            return 0;
        if(neighbour!=target&&ind==houses.size())
            return 1e9;
        
        if(dp[ind][lcolor][neighbour]!=-1) return dp[ind][lcolor][neighbour];
        
        if(houses[ind]!=0)
        {
            if(houses[ind]!=lcolor)
                return func(ind+1,houses,cost,neighbour+1,target,houses[ind],dp);
            else
                return func(ind+1,houses,cost,neighbour,target,lcolor,dp);
        }
        else
        {   
            int minm = INT_MAX;
            for(int j=0;j<cost[ind].size();j++)
            {
                if(j+1!=lcolor)
                    minm = min(minm, cost[ind][j]+func(ind+1,houses,cost,neighbour+1,target,j+1,dp));
                else
                    minm = min(minm, cost[ind][j]+func(ind+1,houses,cost,neighbour,target,lcolor,dp));
                // for(int k=0;k<houses.size();k++)
                //     cout<<houses[k]<<" ";
                // cout<<endl;
            }
            
            // cout<<ind<<" "<<targetleft<<" "<<minm<<endl;
            return dp[ind][lcolor][neighbour]=minm;
        }
    }*//
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        //vector<vector<vector<int>>> dp(m,vector<vector<int>>(n+1,vector<int>(target+1,-1)));
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(target+2,1e9)));
        
        for(int color=0;color<=n;color++)
        {
            dp[m][color][target]=0;
        }
        
        for(int ind=m-1;ind>=0;ind--)
        {
            for(int lcolor=0;lcolor<=n;lcolor++)
            {
                for(int neighbour=target;neighbour>=0;neighbour--)
                {
                    if(houses[ind]!=0)
                    {
                        if(houses[ind]!=lcolor)
                            dp[ind][lcolor][neighbour] = dp[ind+1][houses[ind]][neighbour+1];
                        else
                            dp[ind][lcolor][neighbour] = dp[ind+1][lcolor][neighbour];
                    }
                    else
                    {   
                        int minm = INT_MAX;
                        for(int j=0;j<cost[ind].size();j++)
                        {
                            if(j+1!=lcolor)
                                minm = min(minm, cost[ind][j]+dp[ind+1][j+1][neighbour+1]);
                            else
                                minm = min(minm, cost[ind][j]+dp[ind+1][lcolor][neighbour]);
                            // for(int k=0;k<houses.size();k++)
                            //     cout<<houses[k]<<" ";
                            // cout<<endl;
                        }

                        // cout<<ind<<" "<<targetleft<<" "<<minm<<endl;
                        dp[ind][lcolor][neighbour]=minm;
                    }
                }
            }
        }
        
        int ans=dp[0][0][0];
        
        return ans>=1e9?-1:ans;    
    }
};