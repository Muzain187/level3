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

void printLevelWise(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> pendingNode;
    pendingNode.push(root);
    
    while(pendingNode.size() != 0){
        TreeNode<int>*front = pendingNode.front();
        pendingNode.pop();
        cout<<front->data<<":";
        
        for(int i=0; i<front->children.size(); i++){
            
            cout<<front->children[i]->data;
            if(i+1 != front->children.size())
                cout<<",";
            pendingNode.push(front->children[i]);
        }
        cout<<endl;
    }
}
