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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        map<int,map<int,multiset<int>>> storage;
        vector<vector<int>> ans;
        
        if(root==NULL) return ans;
        queue<pair<TreeNode*,pair<int,int>>> q;
        
        q.push({root,{0,0}});
        
        while(!q.empty())
        {
            TreeNode* node = q.front().first;
            int level = q.front().second.first;
            int col = q.front().second.second;
            storage[col][level].insert(node->val);
            q.pop();
            if(node->left) q.push({node->left,{level+1,col-1}});
            if(node->right) q.push({node->right,{level+1,col+1}});
        }
        
        for(auto maps:storage)
        {
            vector<int> temp;
            
            for(auto sets:maps.second)
            {
                for(auto vals:sets.second)
                    temp.push_back(vals);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
    }
};