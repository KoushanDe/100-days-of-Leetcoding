/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* makeTree(vector<int>& inorder, int start, int end)
{
    if(start>end) return NULL;
    
    int index=-1;
    int maxm = INT_MIN;
    for(int i=start;i<=end;i++)
    {
        if(inorder[i]>maxm)
        {
            maxm=inorder[i];
            index=i;
        }
    }
    
    TreeNode* root = new TreeNode(inorder[index]);
    
    root->left = makeTree(inorder,start,index-1);
    root->right = makeTree(inorder,index+1,end);
    
    return root;
}
TreeNode* Solution::buildTree(vector<int> &A) {
    int n = A.size();
    if(n==0) return NULL;
    TreeNode* root = makeTree(A,0,n-1);
    
    return root;
}
