/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    if(A==NULL) return ans;
    
    queue<TreeNode*> q;
    q.push(A);
    
    while(!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();
        
        ans.push_back(node->val);
        
        if(node->right) q.push(node->right);
        if(node->left) q.push(node->left);
    }
    
    reverse(ans.begin(),ans.end());
    
    return ans;
}
