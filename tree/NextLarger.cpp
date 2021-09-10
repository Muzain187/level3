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
TreeNode<int>* getNextLargerElement(TreeNode<int>* root,TreeNode<int>* larger,int x){
    if(larger == NULL && root->data > x)
        larger = root;
    
    else if(root->data > x && root->data < larger->data) 
        larger = root;
    
    for(int i=0; i< root->children.size(); i++)
        return getNextLargerElement(root->children[i],larger,x);
    
    return larger;
}


TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
  	if(root == NULL)
        return root;
    
    TreeNode<int>* ans = NULL;
    if(root->data > x)
        ans = root;
    

    for(int i=0; i<root->children.size(); i++)
        return getNextLargerElement(root->children[i],ans,x);
    
    return ans;

}
