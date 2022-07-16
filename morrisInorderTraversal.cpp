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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root==NULL) return ans;
        
        TreeNode* curr = root;
        TreeNode* prev;
        
        while(curr!=0)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                prev = curr->left;
                
                while(prev->right&&prev->right!=curr)
                    prev=prev->right;
                
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    curr=curr->left;
                }
                else
                {
                    ans.push_back(curr->val);
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        
        return ans;
       
    }
};