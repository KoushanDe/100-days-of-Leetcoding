#include<bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) 
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> parents;
    BinaryTreeNode<int>* target;
        
        queue<BinaryTreeNode<int>*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            BinaryTreeNode<int>* temp = q.front();
            if(temp->data==start) target = temp;
            q.pop();
            
            if(temp->left)
            {
                q.push(temp->left);
                parents[temp->left] = temp;
            }
            if(temp->right)
            {
                q.push(temp->right);
                parents[temp->right] = temp;
            }
        }
        
        set<BinaryTreeNode<int>*> vis;
        
        q.push(target);
        int k=0;
        while(!q.empty())
        {   
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                BinaryTreeNode<int>* temp = q.front();
            q.pop();
            vis.insert(temp);
            
            if(parents.find(temp)!=parents.end())
            {
                if(vis.find(parents[temp])==vis.end())
                    q.push(parents[temp]);
            }
            
            if(temp->left)
            {
                if(vis.find(temp->left)==vis.end())
                    q.push(temp->left);
            }
            
            if(temp->right)
            {
                if(vis.find(temp->right)==vis.end())
                    q.push(temp->right);
            }
            }
            k++;
        }
        
        return k-1;
}
