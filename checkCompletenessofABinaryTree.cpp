/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root==NULL) return true;
        
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        
        while(!q.empty())
        {   
            int flag=0;
            int size = q.size();
            if(size!=1<<level)
                flag=1;
            for(int i=0;i<size;i++)
            {
                TreeNode* node = q.front();
                q.pop();
                
                if(node->left)
                {   
                    if(flag==0)
                        q.push(node->left);
                    else
                        return false;
                }
                else if(node->right) return false;
                if(node->right)
                {   
                    if(flag==0)
                        q.push(node->right);
                    else
                        return false;
                }
                else if(!q.empty()&&q.front()->left)
                    return false;
            }
            level++;
        }
        
        return true;
    }
};