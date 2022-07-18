/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class NodeValue {
    public:
    int minNode,maxNode,maxSum;
    
    NodeValue(int minNode, int maxNode, int maxSum)
    {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSum = maxSum;
    }
};

class Solution {
public:
    int maxm = INT_MIN;
    NodeValue validMaxSum(TreeNode* root)
    {
        if(root==NULL) return NodeValue(INT_MAX,INT_MIN,0);
        
        NodeValue l = validMaxSum(root->left);
        NodeValue r = validMaxSum(root->right);
        
        if(root->val>l.maxNode&&root->val<r.minNode)
        {   
            maxm = max(l.maxSum+r.maxSum+root->val,maxm);
            //cout<<maxm<<endl;
            return NodeValue(min(root->val,l.minNode),max(root->val,r.maxNode),l.maxSum+r.maxSum+root->val);
        }
        
        
        else
        {
            return NodeValue(INT_MIN,INT_MAX,max(l.maxSum,r.maxSum));
        }
    }
    int maxSumBST(TreeNode* root) {
        validMaxSum(root);
        
        return maxm>0?maxm:0;
    }
};