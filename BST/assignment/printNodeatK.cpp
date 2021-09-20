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
void printSubtree(BinaryTreeNode<int>* root,int k){
    if(root == NULL)
        return;
    if(k == 0){
        cout<<root->data<<endl;
        return;
    }
    printSubtree(root->left,k-1);
    printSubtree(root->right,k-1);
}

int printNodeAtk(BinaryTreeNode<int>*root ,int node,int k){
    if(root == NULL)
        return -1;
    if(root->data == node){
        printSubtree(root,k);
        return 0;
    }
    int dl = printNodeAtk(root->left, node, k);
    if (dl != -1)
    {
         if (dl + 1 == k)
            cout << root->data << endl;
         else
            printSubtree(root->right, k-dl-2);
         return 1 + dl;
    }
    int dr = printNodeAtk(root->right, node, k);
    if (dr != -1)
    {
         if (dr + 1 == k)
            cout << root->data << endl;
         else
            printSubtree(root->left, k-dr-2);
         return 1 + dr;
    }
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    // Write your code herez
    printNodeAtk(root,node,k);
    
}
