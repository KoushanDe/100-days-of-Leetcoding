/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

void inorderDLL(BinaryTreeNode<int>* root,BinaryTreeNode<int>*& prev)
{
    if(root==NULL) return;
    
    inorderDLL(root->right,prev);
    
    root->right = prev;
    if(prev) prev->left=root;
    prev=root;
    
    inorderDLL(root->left,prev);
}

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    BinaryTreeNode<int>* head = root;
    BinaryTreeNode<int>* prev = NULL;
    while(head->left)
        head=head->left;
   inorderDLL(root,prev);
   return head;
}