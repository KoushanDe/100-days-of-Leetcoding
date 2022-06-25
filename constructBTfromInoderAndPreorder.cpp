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
class Solution {
public:
    TreeNode* treeHelper(vector<int>& preorder, vector<int>& inorder, map<int,int>& inmap,int instart, int inend,int prestart, int preend)
    {   
        if(instart>inend||prestart>preend) return NULL;
        
        TreeNode* root = new TreeNode(preorder[prestart]);
        //cout<<root->val<<endl;
        
        int ind = inmap[preorder[prestart]];
        int leftsize = ind-instart;
        
        root->left = treeHelper(preorder,inorder,inmap,instart,ind-1,prestart+1,prestart+leftsize);
        root->right = treeHelper(preorder,inorder,inmap,ind+1,inend,prestart+leftsize+1,preend);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inmap;
        int n = inorder.size();
        for(int i=0;i<inorder.size();i++)
            inmap[inorder[i]] = i;
        
        return treeHelper(preorder,inorder,inmap,0,n-1,0,n-1);
    }
};