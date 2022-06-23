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
    bool isEqual(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL&&root2==NULL) return true;
        if(root1==NULL||root2==NULL) return false;
        
        if(root1->val!=root2->val) return false;
        
        return isEqual(root1->left,root2->right)&&isEqual(root1->right,root2->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL) return true;
        
        return isEqual(root->left,root->right);
    }
};