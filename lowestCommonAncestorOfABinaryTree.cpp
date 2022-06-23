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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        
        if(root==p||root==q) return root;
        
        TreeNode* l;
        TreeNode* r;
        
        l = lowestCommonAncestor(root->left,p,q);
        r = lowestCommonAncestor(root->right,p,q);
        
        if(r!=NULL&&l!=NULL) return root;
        if(r==NULL&&l==NULL) return NULL;
        
        return r==NULL? l:r;
    }
};