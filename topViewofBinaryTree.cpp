#include<bits/stdc++.h>
using namespace std;
/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

vector<int> getTopView(TreeNode<int> *root) {
    map<int,int> topview;
    vector<int> ans;
    
    if(root==NULL) return ans;
    
    queue<pair<TreeNode<int>*,int>> q;
    
    q.push({root,0});
    
    while(!q.empty())
    {
        TreeNode<int>* temp = q.front().first;
        int line = q.front().second;
        
        if(topview.find(line)==topview.end())
            topview[line] = temp->val;
        q.pop();
        
        if(temp->left) q.push({temp->left,line-1});
        if(temp->right) q.push({temp->right,line+1});
    }
    
    for(auto maps:topview)
    {
        ans.push_back(maps.second);
    }
    
    return ans;
}