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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> st;
        st.push(root);
        vector<int> inorder;
        while(!st.empty())
        {
            if(root->left)
            {
                st.push(root->left);
                root=root->left;
            }
            else
            {
                TreeNode* node = st.top();
                st.pop();
                
                inorder.push_back(node->val);
                
                if(node->right)
                {
                    st.push(node->right);
                    root=node->right;
                }
            }
        }
        
        int i=0,j=inorder.size()-1;
        
        while(i<j)
        {
            if(inorder[i]+inorder[j]==k)
                return true;
            else if(inorder[i]+inorder[j]>k)
                j--;
            else
                i++;
        }
        
        return false;
    }
};