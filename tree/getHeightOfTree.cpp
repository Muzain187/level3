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

int getHeight(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL)
        return 0;
    if(root->children.size()==0)
        return 1;
    
    int Rootlevel=1;
    int childlevel=0;
    for(int i=0; i<root->children.size(); i++){
        childlevel = getHeight(root->children[i]);
        if(childlevel > Rootlevel)
            Rootlevel = childlevel;
    }
    
    return Rootlevel+1;
        
}
