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
    TreeNode* helper(TreeNode* root)
    {
        TreeNode* node;
        TreeNode* right;
        
        if(root->left==NULL)return root->right;
        if(root->right==NULL)return root->left;
        right = root->right;
        node=root->left;
        while(node->right!=NULL)
            node=node->right;

        node->right=right;

        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        
        if(key==root->val)
        {   
            return helper(root);
        }
        
        TreeNode* node=root;
        while(node)
        {
            if(key<node->val)
            {
                if(node->left!=NULL&&node->left->val==key)
                    node->left = helper(node->left);
                else
                    node=node->left;
            }
            else{
                if(node->right!=NULL&&node->right->val==key)
                    node->right = helper(node->right);
                else
                    node=node->right;
            }
        }
        
        return root;
    }
};