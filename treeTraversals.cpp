#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    
    stack<pair<BinaryTreeNode<int>*, int>> st;
    
    if(root==NULL) return {inorder,preorder,postorder};
    
    st.push({root,1});
    
    while(!st.empty())
    {
        BinaryTreeNode<int>* node = st.top().first;
        int num = st.top().second;
        st.pop();
        
        if(num==1)
        {
            preorder.push_back(node->data);
            st.push({node,2});
            
            if(node->left)
                st.push({node->left,1});
        }
        else if(num==2)
        {
            inorder.push_back(node->data);
            st.push({node,3});
            
            if(node->right)
                st.push({node->right,1});
        }
        else
        {
            postorder.push_back(node->data);
        }
    }
    
    return {inorder,preorder,postorder};
}