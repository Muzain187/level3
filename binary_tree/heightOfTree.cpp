/***********************************************************
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

int height(BinaryTreeNode<int>* root) {
    // Write our code here
    if(root == NULL)
        return 0;
    
    int leftchild = height(root->left);
    int rightchild = height(root->right);
    
    int height = 1;
    if(leftchild > rightchild)
    	return leftchild + 1;
    else if(rightchild >= leftchild)
        return rightchild + 1;

}
