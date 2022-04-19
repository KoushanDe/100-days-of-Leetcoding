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
    TreeNode* first;
    TreeNode* mid;
    TreeNode* last;
    TreeNode* prev;
    
    void recovery(TreeNode* root)
    {
        if(root==NULL)
            return;
        recovery(root->left);
        if(prev!=NULL)
        {
            if(root->val<prev->val && first == NULL)
            {
                first = prev;
                mid = root;
            }
            else if(root->val<prev->val)
            {
                last = root;
            }
            
        }
        prev = root;
        recovery(root->right);
    }
    
    
    void recoverTree(TreeNode* root) {
        
        recovery(root);
        if(last==NULL)
        {
            swap(first->val,mid->val);
        }
        else
        {
            swap(first->val,last->val);
        }
    } 
};