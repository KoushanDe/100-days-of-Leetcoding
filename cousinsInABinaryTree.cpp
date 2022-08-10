/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> ans;
    if(A->val==B) return ans;
    int flag=0;
    queue<TreeNode*> q;
    q.push(A);
    
    while(flag!=2&&!q.empty())
    {
        int size = q.size();
        if(flag==1) flag=2;
        
        for(int i=0;i<size;i++)
        {
            TreeNode* node = q.front();
            q.pop();
            
            if(flag==2)
            ans.push_back(node->val);
            else
            {
                if(node->left&&node->left->val==B||node->right&&node->right->val==B)
                {
                    flag=1;
                }
                else
                {
                    if(node->left) q.push(node->left);
                    if(node->right) q.push(node->right);
                }
            }
        }
    }
    return ans;
}
