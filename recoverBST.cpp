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
    TreeNode* prev=NULL;
    TreeNode* first=NULL;
    TreeNode* mid=NULL;
    TreeNode* last=NULL;
    
    void inorder(TreeNode* root)
    {
        if(root==NULL) return;
        
        inorder(root->left);
        
        if(prev!=NULL&&prev->val>root->val)
        {   
            if(first==NULL)
            {
                first=prev;
                mid=root;
            }
            else
                last=root;
        }
        prev=root;
        
        inorder(root->right);
    }
    
    void recoverTree(TreeNode* root) {
        inorder(root);
        
        if(last)
            swap(first->val,last->val);
        else
            swap(first->val,mid->val);
    }
};