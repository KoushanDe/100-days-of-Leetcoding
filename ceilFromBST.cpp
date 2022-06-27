/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void helper(BinaryTreeNode<int>* node, int x, int& minceil)
{
    if(node==NULL) return;
    
    if(x==node->data)
    {
        minceil=x;
        return;
    }
    else if(x>node->data)
        helper(node->right,x,minceil);
    else
    {
        minceil = node->data;
        helper(node->left,x,minceil);
    }
}

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int minceil=INT_MAX;
    helper(node,x,minceil);
    return minceil==INT_MAX?-1:minceil;
}