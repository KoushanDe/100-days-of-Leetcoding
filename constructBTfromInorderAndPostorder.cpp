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
    TreeNode* treeHelper(vector<int>& inorder, int instart, int inend, vector<int>& revpostorder, int revstart, int revend, map<int,int>& inmap)
    {
        if(instart>inend||revstart>revend) return NULL;
        
        TreeNode* root = new TreeNode(revpostorder[revstart]);
        
        int ind = inmap[revpostorder[revstart]];
        int rightsize = inend-ind;
        root->right = treeHelper(inorder,ind+1,inend,revpostorder,revstart+1,revstart+rightsize,inmap);
        root->left = treeHelper(inorder,instart,ind-1,revpostorder,revstart+rightsize+1,revend,inmap);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        reverse(postorder.begin(),postorder.end()); //reversing to get root right left
        
        map<int,int> inmap;
        int n=inorder.size();
        
        for(int i=0;i<n;i++)
            inmap[inorder[i]]=i;
        
        return treeHelper(inorder,0,n-1,postorder,0,n-1,inmap);
    }
};