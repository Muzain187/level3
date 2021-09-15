/**********************************************************

	Following are the Binary Tree Node class structure and
	the Node class structure

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

	template <typename T>
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/
#include<queue>
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    vector<Node<int>*> v;
    
    if(root == NULL){
        v.push_back(NULL);
         return v;
    }
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
	Node<int> *head = NULL,*tail = NULL;
    
    while(q.size() != 0){
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        if(front == NULL){
            head=NULL;
            tail=NULL;
            if(q.size() != 0)
        		q.push(NULL);
        }
        else{
            Node<int> *newNode = new Node<int>(front->data);
       		if(head == NULL && tail==NULL){
                head = newNode;
                tail = newNode;
                v.push_back(head);
                
            }
            else{
                tail->next = newNode;
                tail = tail->next;
            }
            if(front->left != NULL)
            	q.push(front->left);
            if(front->right != NULL)
            	q.push(front->right);
        }
     
    }
    return v;
}
