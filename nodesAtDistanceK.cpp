/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void initMap(TreeNode* A,int B,TreeNode* &node,map<int,TreeNode*>& parent)
{
    if(A==NULL)
    return;
    
    if(A->val==B)
    node=A;
    
    if(A->left)
    parent[A->left->val]=A;
    if(A->right)
    parent[A->right->val]=A;
    
    initMap(A->left,B,node,parent);
    initMap(A->right,B,node,parent);
}
vector<int> Solution::distanceK(TreeNode* A, int B, int C) {
    vector<int> ans;
    
    map<int,TreeNode*> parent;
    
    TreeNode* node=NULL;
    initMap(A,B,node,parent);
    if(A==NULL||node==NULL) return ans;
    
    queue<pair<TreeNode*,int>> q;
    map<TreeNode*,bool> vis;
    q.push({node,0});
    vis[node]=true;
    
    while(!q.empty())
    {
        TreeNode* curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if(dist>C) break;
        
        if(dist==C)
        ans.push_back(curr->val);
        
        if(curr->left&&!vis[curr->left])
        {
            vis[curr->left]=true;
            q.push({curr->left,dist+1});
        }
        
        if(curr->right&&!vis[curr->right])
        {
            vis[curr->right]=true;
            q.push({curr->right,dist+1});
        }
        
        if(parent[curr->val]!=NULL&&!vis[parent[curr->val]])
        {
            vis[parent[curr->val]]=true;
            q.push({parent[curr->val],dist+1});
        }
        
        
    }
    
    return ans;
    
}
