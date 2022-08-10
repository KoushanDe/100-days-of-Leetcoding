/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if(A==NULL&&B==NULL) return NULL;
    
    int aval = 0, bval=0;
    
    if(A!=NULL) aval=A->val;
    if(B!=NULL) bval=B->val;
    
    if(A==NULL)
    A= new TreeNode(aval+bval);
    else
    A->val = aval+bval;
    
    if(B==NULL)
    B=new TreeNode(0);
    
    A->left = solve(A->left,B->left);
    A->right = solve(A->right,B->right);
    
    return A;
}
