#include<bits/stdc++.h>
using namespace std;
/*************************************************************
 
    Following is the Binary Tree node structure.

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

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    map<int,int> bottomview;
    vector<int> ans;
    
    if(root==NULL) return ans;
    
    queue<pair<BinaryTreeNode<int>*,int>> q;
    
    q.push({root,0});
    
    while(!q.empty())
    {
        BinaryTreeNode<int>* temp = q.front().first;
        int line = q.front().second;
        
        bottomview[line] = temp->data;
        q.pop();
        
        if(temp->left) q.push({temp->left,line-1});
        if(temp->right) q.push({temp->right,line+1});
    }
    
    for(auto maps:bottomview)
    {
        ans.push_back(maps.second);
    }
    
    return ans;
    
}
