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
 bool isFound(TreeNode* root, int target, vector<int>& ans)
 {
     if(root==NULL) return false;
     
     ans.push_back(root->val);
     if(root->val==target) return true;
     
     if(isFound(root->left,target,ans)||isFound(root->right,target,ans))
     return true;
     else{
         ans.pop_back();
         return false;
     }
 }
 
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    
    isFound(A,B,ans);
    return ans;
}
