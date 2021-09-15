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
int depth(BinaryTreeNode<int> *root){
    if(root == NULL)
        return 0;
    int leftChild = depth(root->left);
    int rightChild = depth(root->right);
    
    return min(leftChild,rightChild) + 1;
    
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL)
        return false;
    
    int leftChild = depth(root->left);
    int rightChild = depth(root->right);
    
    return (leftChild == rightChild);
    
}
