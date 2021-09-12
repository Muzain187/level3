/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
   	if(root == NULL)
       return false;
	
    if(root->data == x)
        return true;
    else
        return isNodePresent(root->left,x) || isNodePresent(root->right,x);
    

}
//--------------- OR -----------------

#include<queue>
bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
   if(root == NULL)
       return false;
	
    queue<BinaryTreeNode<int>*> pendingNode;
    pendingNode.push(root);
    
    while(pendingNode.size() != 0){
        BinaryTreeNode<int>* front = pendingNode.front();
        pendingNode.pop();
        
        if(front->data == x)
            return true;
        
        if(front->left != NULL)
            pendingNode.push(front->left);
        if(front->right != NULL)
            pendingNode.push(front->right);
        
    }
    return false;
}
