

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    int rootSum=0,childSum=0;
    for(int i=0; i<root->children.size(); i++)
        rootSum += root->children[i]->data;
    rootSum += root->data;
    
    TreeNode<int> *child=NULL;
    for(int i=0; i<root->children.size(); i++){
        child = maxSumNode(root->children[i]);
    }
	
    if(child == NULL)
        return root;
    for(int i=0;i<child->children.size(); i++)
        childSum += child->children[i]->data;
    childSum += child->data;
    
    if(rootSum > childSum)
        return root;
    else
        return child;
}

//------------------------------  OR  ---------------------------------


