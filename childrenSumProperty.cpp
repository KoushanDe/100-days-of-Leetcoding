/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int childrenSum(BinaryTreeNode<int>* root)
{
    int left = 0;
    int right = 0;
    
    if(root->left)
    {
        root->left->data = max(root->data,root->left->data);
        left = childrenSum(root->left);
    }
    
    if(root->right)
    {
        root->right->data = max(root->data,root->right->data);
        right = childrenSum(root->right);
    }
    
    if(root->left||root->right) root->data = left+right;
    
    return root->data;
}
void changeTree(BinaryTreeNode < int > * root) {
    if(root==NULL) return;
    
    childrenSum(root);
}  