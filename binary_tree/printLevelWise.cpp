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
#include<queue>

void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL)
        return;
	    
    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);
    
    while(pendingNode.size() != 0){
        BinaryTreeNode<int>* front = pendingNode.front();
        pendingNode.pop();
        cout<<front->data<<":";
        if(front->left == NULL){
            cout<<"L:-1,";
        }
        else{
            cout<<"L:"<<front->left->data<<",";
        	pendingNode.push(front->left);
        }
         if(front->right == NULL){
            cout<<"R:-1";
        }
        else{
            cout<<"R:"<<front->right->data<<"";
        	pendingNode.push(front->right);
        }
        cout<<endl;
    }
}
