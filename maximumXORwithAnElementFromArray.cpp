class Node{
  public:
    Node* links[2];
    
    bool containsKey(int ind)
    {
        return links[ind]!=NULL;
    }
    
    void put(int ind, Node* node)
    {
        links[ind] = node;
    }
    
    Node* get(int ind)
    {
        return links[ind];
    }
};

class Trie{
  private:
    Node* root;
    
  public:
    
    Trie(){
        root = new Node();
    }
    
    void insert(int num)
    {
        Node* node = root;
        
        for(int i=31;i>=0;i--)
        {
            if(!node->containsKey((num>>i)&1))
                node->put((num>>i)&1,new Node());
            
            node = node->get((num>>i)&1);
        }
    }
    
    int maxXOR(int num)
    {
        int XOR = 0;
        Node* node = root;
        for(int i=31;i>=0;i--)
        {   
            int ibit = (num>>i)&1;
            if(node->containsKey(!ibit))
            {
                XOR = XOR | (1<<i);
                node = node->get(!ibit);
            }
            else
                node = node->get(ibit);
        }
        
        return XOR;
    }
    
};
class Solution {
public:
    static bool comparemi(vector<int>& v1, vector<int>& v2)
    {
        return v1[1]<v2[1];
    }
    
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        Trie T;
        int m = queries.size();
        vector<int> ans(m,0);
        
        vector<vector<int>> sortedQueries;
        
        for(int i=0;i<m;i++)
        {
            sortedQueries.push_back({queries[i][0],queries[i][1],i});
        }
        
        sort(sortedQueries.begin(),sortedQueries.end(),comparemi);
        sort(nums.begin(),nums.end());
        
        int j=0;
        
        for(int i=0;i<m;i++)
        {
            int x = sortedQueries[i][0];
            int m = sortedQueries[i][1];
            
            if(m<nums[0])
            {
                ans[sortedQueries[i][2]] = -1;
                continue;
            }
            
            while(j<nums.size()&&nums[j]<=m)
            {
                T.insert(nums[j]);
                j++;
            }

            
            ans[sortedQueries[i][2]] = T.maxXOR(x);
            
        }
        
        return ans;
    }
};