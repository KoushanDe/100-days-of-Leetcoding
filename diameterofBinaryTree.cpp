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
    int findHeight(TreeNode* root, int& maxDia)
    {
        if(root==NULL)
            return 0;
        
        int left = findHeight(root->left,maxDia);
        int right = findHeight(root->right,maxDia);
        
        maxDia = max(maxDia,left+right);
        
        return 1+max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDia = 0;
        findHeight(root,maxDia);
        return maxDia;
    }
};