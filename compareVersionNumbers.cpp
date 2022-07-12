
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i=0,j=0;
        
        while(i<version1.size()||j<version2.size())
        {   
            string temp1="",temp2="";
            
            while(i<version1.size()&&version1[i]!='.')
                temp1 = temp1+version1[i++];
            
            while(j<version2.size()&&version2[j]!='.')
                temp2 = temp2+version2[j++];
            
            //cout<<temp1<<" "<<temp2<<endl;
            i++,j++;
            
            int v1 = temp1==""?0:stoi(temp1);
            int v2 = temp2==""?0:stoi(temp2);
            
            if(v1<v2) return -1;
            if(v1>v2) return 1;
        }
        
        return 0;
    }
};