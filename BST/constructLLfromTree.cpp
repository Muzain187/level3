Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
	// return constructList(root)->head;
    if(root == NULL)
        return NULL;
    
    Node<int>* leftNode = constructLinkedList(root->left);
    Node<int>* rightNode = constructLinkedList(root->right);
    
    Node<int>* rootNode = new Node<int>(root->data);
    
    if(leftNode != NULL){
        Node<int>* temp = leftNode;
        while(temp->next != NULL)
            temp = temp->next;
        temp->next = rootNode;
    }
    rootNode->next = rightNode;
    
    if(leftNode != NULL)
        return leftNode;
    return rootNode;

 
