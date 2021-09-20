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

***********************************************************/

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    if(root == NULL)
        return NULL;
    if(root->data == data){
        vector <int>*v = new vector<int>();
        v->push_back(root->data);
        return v;
    }
    vector<int> *leftChild = getPath(root->left,data);
    if(leftChild != NULL){
        leftChild->push_back(root->data);
        return leftChild;
    }
     vector<int> *rightChild = getPath(root->right,data);
    if(rightChild != NULL){
        rightChild->push_back(root->data);
        return rightChild;
    }
    
}
