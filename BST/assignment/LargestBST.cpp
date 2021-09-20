/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
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
	};
	
    
    Start from root and do an inorder traversal of the tree.
    For each node N, check whether the subtree rooted with N is BST or not. 
    If BST, then return size of the subtree rooted with N.
    Else, recur down the left and right subtrees, 
    and return the maximum of values returned by left and right subtrees. 
***********************************************************/
#include<climits>
int size(BinaryTreeNode<int> *node)
{
    if (node == NULL)
        return 0;
    else
        return max(size(node->left),size(node->right))+1;
}

bool isBST(BinaryTreeNode<int>* root,int k1,int k2){
    if(root == NULL)
        return true;
    
    if(root->data < k1 || root->data > k2)
        return false;
    
    bool leftChild = isBST(root->left,k1,root->data);
    bool rightChild = isBST(root->right,root->data,k2);
    
    return leftChild&&rightChild;
}

bool isBST(BinaryTreeNode<int> *root) {
	return isBST(root,INT_MIN,INT_MAX);
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL)
        return 0;
    
    if(isBST(root)){
        return size(root);
    }
    else{
        int leftTree = largestBSTSubtree(root->left);
        int rightTree = largestBSTSubtree(root->right);
        return max(leftTree,rightTree);
    }
}
