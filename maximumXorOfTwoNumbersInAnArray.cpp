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
                XOR += (1<<i);
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
    int findMaximumXOR(vector<int>& nums) {
        Trie T;
        
        for(int i=0;i<nums.size();i++)
        {
            T.insert(nums[i]);
        }
        
        int maxXor = 0;
        
        for(int i=0;i<nums.size();i++)
        {
            maxXor = max(maxXor,T.maxXOR(nums[i]));
        }
        
        return maxXor;
    }
};