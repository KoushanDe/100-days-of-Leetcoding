#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL)
            return root;
        queue<Node*> q;
        Node* curr;
        q.push(root);
        q.push(NULL);
        while(!q.empty())
        {   
            if(q.front()!=NULL){
            curr = q.front();
            q.pop();
            curr->next = q.front();
            if(curr->left!=NULL)q.push(curr->left);
            if(curr->right!=NULL)q.push(curr->right);
            }
            else
            {
                q.pop();
                if(!q.empty())
                q.push(NULL);
            }
        }
        return root;
    }
};