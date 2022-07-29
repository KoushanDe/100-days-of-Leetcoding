class Solution {
public:
    bool canChange(string start, string target) {
        int i=0,j=0;
        
        while(true)
        {
            while(start[i]=='_'&&i<start.size())
                i++;
            while(target[j]=='_'&&j<target.size())
                j++;
            
            //cout<<start[i]<<" "<<target[j]<<endl;
            
            if(i==start.size()&&j==target.size())
                break;
            else if(i==start.size()||j==target.size())
                return false;
            
            if(start[i]!=target[j])
                return false;
            
            if(start[i]=='L'&&j>i)
                return false;
            if(start[i]=='R'&&j<i)
                return false;
            i++,j++;
        }
        
        return true;
    }
};