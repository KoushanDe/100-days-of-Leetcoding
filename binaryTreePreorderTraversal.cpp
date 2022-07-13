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
    void preorder(TreeNode* root, vector<int>& ans)
    {
        if(root==NULL)
            return;
        
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        preorder(root,ans);
        
        return ans;
    }
};

//ITERATIVE

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> preorder;
        
        TreeNode* node = root;
        
        while(true)
        {
            if(node!=NULL)
            {
                preorder.push_back(node->val);
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty()) break;
                
                node=st.top();
                st.pop();
                node=node->right;
            }
        }
        
        return preorder;
    }
};