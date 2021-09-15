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
#include<stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL)
        return;
    stack<BinaryTreeNode<int>*> odd;//left to right
    stack<BinaryTreeNode<int>*> even;//right to left
    
    odd.push(root);
   
    int level = 1;
    while(!odd.empty() || !even.empty()){
        if(level%2 != 0){
            while(!odd.empty()){
                BinaryTreeNode<int> *top = odd.top();
                odd.pop();
                cout<<top->data<<" ";
                if(top->left != NULL)
                    even.push(top->left);
                if(top->right != NULL)
                    even.push(top->right);
            }
        }
        else{
             while(!even.empty()){
                BinaryTreeNode<int> *Eventop = even.top();
                even.pop();
                cout<<Eventop->data<<" ";
                if(Eventop->right != NULL)
                    odd.push(Eventop->right);
                if(Eventop->left != NULL)
                    odd.push(Eventop->left);
            }
        }
        cout<<endl;
        level++;
    }
    
}
