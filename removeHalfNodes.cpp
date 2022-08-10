/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A) {
    if(A==NULL) return NULL;
    
    A->left = solve(A->left);
    A->right = solve(A->right);
    
    if(!A->left&&!A->right)
    return A;
    
    if(!A->left) return A->right;
    if(!A->right) return A->left;
    
    return A;
}
