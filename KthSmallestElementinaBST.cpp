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
    TreeNode* returnKthSmallest(TreeNode* root, int& c ,int k)
    {
        if(root == NULL)
            return NULL;
        
        TreeNode* temp = returnKthSmallest(root->left, c, k);
        if(temp!=NULL)
            return temp;
        c++;
        if(c==k)
            return root;
        temp = returnKthSmallest(root->right, c, k);
        if(temp!=NULL)
            return temp;
        
        return NULL;
    }
    int kthSmallest(TreeNode* root, int k) {
        int c = 0;
        TreeNode* ans = returnKthSmallest(root,c,k);
        return ans->val;
    }
};