#include<bits/stdc++.h>
#include<iostream>

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
    int f(TreeNode* root,int nodecam,int parentcam,map<pair<TreeNode*,pair<int,int>>, int>& dp)
    {
        if(root==NULL)
            return nodecam?1e9:0;
        
        if(dp.find({root,{nodecam,parentcam}})!=dp.end())
            return dp[{root,{nodecam,parentcam}}];
        
        if(nodecam==1||parentcam==1) //3 cases here 1,1  1,0  0,1 same recursion for all three
        {
            int leftcam=min(f(root->left,0,nodecam,dp),f(root->left,1,nodecam,dp));
            int rightcam=min(f(root->right,0,nodecam,dp),f(root->right,1,nodecam,dp));
            return dp[{root,{nodecam,parentcam}}] = nodecam+leftcam+rightcam;
        }
        else //last case when nodecam=0 & parentcam=0
        {
            int leftCompulasoryRightOptional=f(root->left,1,0,dp)+ min(f(root->right,0,0,dp),f(root->right,1,0,dp));
            int rightCompulasoryLeftOptional=f(root->right,1,0,dp)+ min(f(root->left,0,0,dp),f(root->left,1,0,dp));
            
            return dp[{root,{nodecam,parentcam}}] = min(leftCompulasoryRightOptional,rightCompulasoryLeftOptional);
        }
    }
    int minCameraCover(TreeNode* root) {
        map<pair<TreeNode*,pair<int,int>>, int> dp;
        return min(f(root,0,0,dp),f(root,1,0,dp));
    }
};