/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::verticalSum(TreeNode* A) {
    vector<int> ans;
    if(A==NULL) return ans;
    map<int,vector<int>> nodes;
    queue<pair<TreeNode*,int>> q;
    q.push({A,0});
    
    while(!q.empty())
    {
        TreeNode* node = q.front().first;
        int line = q.front().second;
        q.pop();
        
        nodes[line].push_back(node->val);
        if(node->left) q.push({node->left,line-1});
        if(node->right) q.push({node->right,line+1});
    }
    
    for(auto m:nodes)
    {   
        int sum=0;
        for(auto elem:m.second)
        sum+=elem;
        
        ans.push_back(sum);
    }
    
    return ans;
}
