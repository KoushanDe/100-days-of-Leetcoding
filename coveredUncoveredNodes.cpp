/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
long Solution::coveredNodes(TreeNode* A) {
    if(A==NULL) return 0;
    long long uncovsum=0;
    
    queue<TreeNode*> q;
    q.push(A);
    long long covsum=0;
    
    while(!q.empty())
    {   
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            TreeNode* cur = q.front();
            q.pop();
            
            if(i==0||i==size-1) uncovsum+=cur->val;
            else covsum+=cur->val;
            
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
    
    return abs(uncovsum-covsum);
}
