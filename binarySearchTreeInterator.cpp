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
class BSTIterator {
public:
    TreeNode* curr;
    TreeNode* temp;
    TreeNode* temp2;
    stack<TreeNode*> inorder;
    BSTIterator(TreeNode* root) {
        curr = root;
        while(true)
        {
            inorder.push(curr);
            curr = curr->left;
            if(curr==NULL)
                break;
        }
    }
    
    int next() {
        temp = inorder.top();
        inorder.pop();
        if(temp->right!=NULL)
        {
            temp2 = temp->right;
            while(true)
            {
                inorder.push(temp2);
                temp2 = temp2->left;
                if(temp2==NULL)
                    break;
            }
        }
        return temp->val;
    }
    
    bool hasNext() {
        return !inorder.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */