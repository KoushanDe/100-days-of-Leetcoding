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
    void sortBST(TreeNode* curr, vector<int>& inorder)
    {
        if(curr==NULL)
            return;
        
        sortBST(curr->left,inorder);
        inorder.push_back(curr->val);
        sortBST(curr->right,inorder);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> inorder;
       sortBST(root,inorder);
        TreeNode* head = new TreeNode(inorder[0]);
        TreeNode* temp =  head;
        for(int i=1;i<inorder.size();i++)
        {
            temp->right = new TreeNode(inorder[i]);
            temp = temp->right;
        }
        return head;
    }
};