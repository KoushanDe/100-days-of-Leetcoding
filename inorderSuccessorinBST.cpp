// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* ans;
        
        while(root)
        {
            if(x->data>=root->data)
            root=root->right;
            else
            {
                ans = root;
                root=root->left;
            }
        }
        
        return ans;
    }
};
