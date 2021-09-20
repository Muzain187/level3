/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
    };

************************************************************/
BinaryTreeNode<int>* insertDuplicate(BinaryTreeNode<int>* root){
    if(root == NULL)
        return root;
    
    BinaryTreeNode<int>* leftNode = insertDuplicate(root->left);
    BinaryTreeNode<int>* rightNode = insertDuplicate(root->right);
    
    BinaryTreeNode<int> *duplicate = new BinaryTreeNode<int>(root->data);
    root->left = duplicate;
    duplicate->left = leftNode;
    
    return root;
}

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL)
        return;
    root = insertDuplicate(root);
}
