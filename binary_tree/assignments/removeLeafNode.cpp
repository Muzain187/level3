/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
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

***********************************************************/

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL)
        return root;
    if(root->left==NULL && root->right==NULL){
        return NULL;
    }
    
    BinaryTreeNode<int>* leftChild = removeLeafNodes(root->left);
    BinaryTreeNode<int>* rightChild = removeLeafNodes(root->right);
    
    root->left = leftChild;
    root->right = rightChild;
    
    return root;
}
