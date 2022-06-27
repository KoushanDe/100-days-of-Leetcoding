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

//by reference
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

//iterative
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        
        st.push(root);
        
        int count=0;
        
        while(!st.empty())
        {
            if(root->left)
            {
                st.push(root->left);
                root=root->left;
            }
            else{
                TreeNode* curr = st.top();
                st.pop();
                //cout<<curr->val<<" ";
                count++;
                if(count==k) return curr->val;
                if(curr->right) 
                {
                    st.push(curr->right);
                    root=curr->right;
                }
            }
        }
        
        return 0;
    }
};