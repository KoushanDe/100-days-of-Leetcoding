#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

void addLeftBoundary(TreeNode<int>* root, vector<int>& ans)
{    
    if(root==NULL)return;
    if(root->left==NULL&&root->right==NULL) return;
    
    ans.push_back(root->data);
    
    if(root->left!=NULL)
        addLeftBoundary(root->left,ans);
    else
        addLeftBoundary(root->right,ans);
}

void addLeafs(TreeNode<int>* root, vector<int>& ans)
{
    if(root==NULL) return;
    
    if(root->left==NULL&&root->right==NULL)
    ans.push_back(root->data);
    
    addLeafs(root->left,ans);
    addLeafs(root->right,ans);
}

void addRightBoundary(TreeNode<int>* root, stack<int>& st)
{    
    if(root==NULL)return;
    if(root->left==NULL&&root->right==NULL) return;
    
    st.push(root->data);
    
    if(root->right!=NULL)
        addRightBoundary(root->right,st);
    else
        addRightBoundary(root->left,st);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root->left!=NULL||root->right!=NULL)
    ans.push_back(root->data);
    stack<int> st;
    addLeftBoundary(root->left,ans);
    addLeafs(root,ans);
    addRightBoundary(root->right,st);
    
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}