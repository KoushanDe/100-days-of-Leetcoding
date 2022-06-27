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

class Solution {
public:
    void findKthNode(TreeNode* root,int k, int& node,int& count)
    {
        if(root==NULL) return;
        if(count==k) return;
        
        findKthNode(root->left,k,node,count);
        
        count++;
        //cout<<root->val<<" "<<count<<endl;
        if(count==k) node=root->val;
        
        findKthNode(root->right,k,node,count);
    }
    int kthSmallest(TreeNode* root, int k) {
        int node;
        int count=0;
        findKthNode(root,k,node,count);
        return node;
    }
};