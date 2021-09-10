/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

//helper function
TreeNode<int>* max(TreeNode<int>*root,TreeNode<int>*Max){
    if(root->data >= Max->data)
        Max = root;
    
    if(root->children.size() == 0)
        return Max;

    for(int i=0; i<root->children.size(); i++)
    	Max = max(root->children[i],Max); 
	return Max;
}


TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    TreeNode<int>*Max = root;
    for(int i=0;i<root->children.size(); i++)
    	Max =  max(root->children[i],Max);
    
    return Max;
}


//******************************   OR    **********************************
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL)
    	return root;
    	
    	
    TreeNode<int>*Max = root;
    for(int i=0;i<root->children.size(); i++){
    	TreeNode<int>*maxChild = maxDataNode(root->children[i]);
    	if(maxchild->data > Max->data)
    		Max = maxChild;
    }
    return Max;
}



