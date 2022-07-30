class Solution {
public:
    int mod = (int)(1e9+7);
    
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<int> newKnow(n,0);
        newKnow[0] = 1;
        int noOfPeepSharing=0;
        
        for(int i=1;i<n;i++)
        {
            int newShare = i-delay<0?0:newKnow[i-delay];
            int newForget = i-forget<0?0:newKnow[i-forget];
            
            noOfPeepSharing = (noOfPeepSharing+newShare)%mod;
            noOfPeepSharing = (noOfPeepSharing-newForget+mod)%mod;
            newKnow[i] = noOfPeepSharing;
        }
        
        // for(int i=0;i<n;i++)
        //     cout<<newKnow[i]<<" ";
        int totalKnow=0;
        for(int i=n-forget;i<n;i++)
        {
            totalKnow = (totalKnow+newKnow[i])%mod;
        }
        
        return totalKnow;
    }
};