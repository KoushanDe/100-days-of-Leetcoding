/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int Solution::minDepth(TreeNode* A) {
   if(A==NULL) return 0;
    
    int lh = minDepth(A->left);
    int rh = minDepth(A->right);
    
    if(lh==0&&rh==0)
    return 1;
    if(lh==0||rh==0)
    return lh?1+lh:1+rh;
    
    return 1+min(lh,rh); 
}
