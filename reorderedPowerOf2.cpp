class Solution {
public:
    bool reorderedPowerOf2(int n) {
        unordered_set<string> powerOf2;
        int maxm = (int)(1e9);
        
        int p=1;
        
        while(p<=maxm)
        {   
            string temp = to_string(p);
            sort(temp.begin(),temp.end());
            powerOf2.insert(temp);
            p*=2;
        }
        
        string temp2 = to_string(n);
        sort(temp2.begin(),temp2.end());
        
        if(powerOf2.find(temp2)!=powerOf2.end())
            return true;
        
        return false;
        
    }
};