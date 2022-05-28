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
    int calcPathsum(TreeNode* root, int& sum)
    {
        if(root==NULL)
            return 0;
        
        int left = max(0,calcPathsum(root->left,sum));
        int right = max(0,calcPathsum(root->right,sum));
        
        sum = max(sum,left+right+root->val);
        
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        calcPathsum(root,sum);
        return sum;
    }
};