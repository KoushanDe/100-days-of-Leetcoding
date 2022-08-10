/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
void preorder(TreeNode* A,int diag,map<int,vector<int>>& nodes)
{   
    if(A==NULL)
    return;
    nodes[diag].push_back(A->val);
    
    preorder(A->left,diag+1,nodes);
    preorder(A->right,diag,nodes);
}
vector<int> Solution::solve(TreeNode* A) {
    vector<int> ans;
    map<int,vector<int>> nodes;
    
    // queue<pair<TreeNode*,int>> q;
    // q.push({A,0});
    
    // while(!q.empty())
    // {
    //     TreeNode* node = q.front().first;
    //     int diag = q.front().second;
    //     q.pop();
        
    //     nodes[diag].push_back(node->val);
    //     if(node->right) q.push({node->right,diag});
    //     if(node->left) q.push({node->left,diag+1});
    // }
    preorder(A,0,nodes);
    
    for(auto m:nodes)
    {
        for(auto elem:m.second)
            ans.push_back(elem);
    }
    
    return ans;
}
