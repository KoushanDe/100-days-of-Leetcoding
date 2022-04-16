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
    TreeNode* convertHelper(TreeNode* root, int& sum)
    {
        if(root==NULL)
            return NULL;
        convertHelper(root->right,sum);
        sum+=root->val;
        root->val=sum;
        convertHelper(root->left,sum);
        return root;
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        convertHelper(root, sum);
        return root;
    }
};