/************************************************************

    Following is the TreeNode class structure

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

int floorInBST(TreeNode<int> * root, int X)
{
    int floor=-1;
    
    while(root)
    {
        if(X==root->val)
            return X;
        else if(X<root->val)
            root=root->left;
        else
        {
            floor=root->val;
            root=root->right;
        }
    }
    
    return floor;
}