#include<bits/stdc++.h>
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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        queue<pair<TreeNode*,int>> q;
        
        q.push({root,0});
        
        int maxwidth=0;
        
        while(!q.empty())
        {
            int size = q.size();
            int minm=q.front().second;
            int first,last;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front().first;
                long long index = q.front().second-minm;
                
                if(i==0) first = index;
                if(i==size-1) last = index;
                q.pop();
                
                if(temp->left)q.push({temp->left,index*2+1});
                if(temp->right)q.push({temp->right,index*2+2});
                
            }
            maxwidth=max(maxwidth,(last-first+1));
        }
        
        return maxwidth;
    }
};