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
    TreeNode* buildTree(vector<int>& preorder, int start, int end)
    {   
        if(start>end) return NULL;
        int rootval = preorder[start];
        TreeNode* root = new TreeNode(rootval);
        int leftlast=end;
        for(int i=start+1;i<=end;i++)
        {
            if(preorder[i]>rootval)
            {
                leftlast=i-1;
                break;
            }
        }
        
        root->left = buildTree(preorder,start+1,leftlast);
        root->right = buildTree(preorder,leftlast+1,end);
        
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildTree(preorder,0,preorder.size()-1);
    }
};