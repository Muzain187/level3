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
#include<climits>
class BST {
    // Define the data members
    BinaryTreeNode<int> *root;
   public:
    BST() { 
        // Implement the Constructor
        root=NULL;
    }

	/*----------------- Public Functions of BST -----------------*/
	private:
    int small(BinaryTreeNode<int>* root){
        if(root == NULL)
            return INT_MAX;
        
        return min(root->data,min(small(root->left),small(root->right)));
    }
	BinaryTreeNode<int>* remove(int data,BinaryTreeNode<int>* node){
        if(node == NULL)
            return NULL;
        
        if(node->data == data){
            if(node->left==NULL && node->right==NULL)
                return NULL;
            else if(node->left == NULL){
                return node->right;
            }
            else if(node->right == NULL){
                return node->left;
            }
            else{
                int replace = small(node->right);
                node->data = replace;
                node->right = remove(replace,node->right);
                return node;
            }
    	}
        if(data < node->data){
            BinaryTreeNode<int>* leftNode = remove(data,node->left);
        	node->left = leftNode; 
        }    
        if(data > node->data){
            BinaryTreeNode<int>* rightNode  =remove(data,node->right);
         	node->right = rightNode;   
        }
    }
    
    public:
    void remove(int data) { 
        // Implement the remove() function 
        this->root = remove(data,root);
    }

    private:
    void print(BinaryTreeNode<int>* node) { 
        // Implement the print() function
        if(node == NULL){
            return;
        }
        cout<<node->data<<":";
        if(node->left != NULL)
            cout<<"L:"<<node->left->data<<",";
        if(node->right != NULL)
            cout<<"R:"<<node->right->data;
        cout<<endl;
        print(node->left);
        print(node->right);
    }
	public:
    void print(){
        print(root);
    }
    
    private :
    BinaryTreeNode<int>* insert(int data,BinaryTreeNode<int>* node){
        if(node == NULL){
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if(data <= node->data){
        	BinaryTreeNode<int>*leftData = insert(data,node->left);
        	node->left = leftData;
        }
        if(data > node->data){
            BinaryTreeNode<int>* rightData = insert(data,node->right);
        	node->right = rightData;
        }
        return node;
    }
    public:
    void insert(int data) { 
        // Implement the insert() function 
        this->root = insert(data,root);
    }

    private:
    
    bool search(int data,BinaryTreeNode<int> *node){
        if(node == NULL)
            return false;
        
        if(node->data == data)
            return true;
        else if(root->data < data)
            return  search(data,node->right);
        else {
            return search(data,node->left);
        }
    }
    
    public:
    
    bool search(int data) {
		// Implement the search() function 
        return search(data,root);
    }
};
