/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*> parents;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->left)
            {
                q.push(temp->left);
                parents[temp->left] = temp;
            }
            if(temp->right)
            {
                q.push(temp->right);
                parents[temp->right] = temp;
            }
        }
        
        set<TreeNode*> vis;
        
        q.push(target);
        
        while(!q.empty()&&k>0)
        {   
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                TreeNode* temp = q.front();
            q.pop();
            vis.insert(temp);
            
            if(parents.find(temp)!=parents.end())
            {
                if(vis.find(parents[temp])==vis.end())
                    q.push(parents[temp]);
            }
            
            if(temp->left)
            {
                if(vis.find(temp->left)==vis.end())
                    q.push(temp->left);
            }
            
            if(temp->right)
            {
                if(vis.find(temp->right)==vis.end())
                    q.push(temp->right);
            }
            }
            k--;
        }
        
        vector<int> ans;
        
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        
        return ans;
    }
};