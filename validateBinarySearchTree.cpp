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
    bool helper(TreeNode* root, long long& prev)
    {
        if(root==NULL)return true;
        
        if(helper(root->left,prev)==false)
            return false;
        
        if(root->val<=prev)
            return false;
        prev=root->val;
        
        if(helper(root->right,prev)==false)
            return false;
        
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long prev = (long long)INT_MIN-1;
        return helper(root,prev);
    }
};