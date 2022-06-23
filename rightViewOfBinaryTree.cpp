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
 /**RECURSIVE SOLUTION**
  * class Solution {
public:
    void rsv(TreeNode* root, int level, vector<int>& ans)
    {
        if(root==NULL) return;
        
        if(level==ans.size()) ans.push_back(root->val);
        
        rsv(root->right,level+1,ans);
        rsv(root->left,level+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        rsv(root,0,ans);
        
        return ans;
    }
};**/
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int,int> rightview;
        vector<int> ans;
        
        if(root==NULL) return ans;
        
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            TreeNode* temp = q.front().first;
            int level = q.front().second;
            
            rightview[level] = temp->val;
            /*
            For leftview
            if(leftview.find(level)==leftview.end())
                leftview[level] = temp->val;
            */
            q.pop();
            
            if(temp->left) q.push({temp->left,level+1});
            if(temp->right) q.push({temp->right,level+1});
        }
        
        for(auto maps:rightview)
            ans.push_back(maps.second);
        
        return ans;
    }
};