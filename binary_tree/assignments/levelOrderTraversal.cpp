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
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    // cout<<root->data;
    
    while(q.size() != 0){
        BinaryTreeNode<int>* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(q.size() != 0)
        		q.push(NULL);
            else
                break;
        }
        else{
            cout<<front->data<<" "; 
            
            if(front->left != NULL)
                q.push(front->left);
            if(front->right != NULL)
                q.push(front->right);
        }
     
    }
    
}
