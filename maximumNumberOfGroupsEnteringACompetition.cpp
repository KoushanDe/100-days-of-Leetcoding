class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        int n = grades.size();
        
        int groups=0,groupsize=1;
        int i=0;
        while(i<n)
        {
            if(i+groupsize-1<n)
            {
                groups++;
                i = i+groupsize;
                groupsize++;
            }
            else
                break;
        }
        
        return groups;
    }
};