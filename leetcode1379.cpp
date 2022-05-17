#include<bits/stdc++.h>
using namespace std;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
public:
    bool dfsOrig(TreeNode* root, TreeNode* target, vector<string>& path)
    {
        if(root == NULL)
            return false;
        else if(root == target)
            return true;
        
        path.push_back("left");
        if(dfsOrig(root->left,target,path)==true)
            return true;
        path.pop_back();
        path.push_back("right");
        if(dfsOrig(root->right,target,path)==true)
            return true;
        path.pop_back();
        return false;
    }
    TreeNode* dfsClone(TreeNode* cloned, vector<string>& path)
    {
        for(int i=0;i<path.size();i++)
        {   
            cout<<path[i];
            if(path.at(i)=="left")
                cloned = cloned->left;
            else
                cloned = cloned->right;
        }
        return cloned;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        vector<string> path;
        dfsOrig(original,target,path);
        return dfsClone(cloned,path);
    }
};

//This is also the solution for the follow up question