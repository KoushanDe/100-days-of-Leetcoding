#include<bits/stdc++.h>
using namespace std;

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    void dfs(TreeNode* root,pair<int,int> &deepsum, int d)
    {
        if(root==NULL)
            return;
        
        dfs(root->left,deepsum,d+1);
        if(d == deepsum.second)
        {
            deepsum.first+=root->val;
        }
        else if(d > deepsum.second)
        {
            deepsum.second = d;
            deepsum.first = root->val;
        }
        
        dfs(root->right,deepsum,d+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        pair<int,int> deepsum = {0,0};
        dfs(root,deepsum,0);
        return deepsum.first;
    }
};