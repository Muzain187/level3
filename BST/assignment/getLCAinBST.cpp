
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    if(root == NULL)
        return -1;
    
    if(val1 == root->data)
        return val1;
    if(val2 == root->data)
        return val2;
    
    if(root->data<val1&&root->data<val2){
        return getLCA(root->right,val1,val2);
    }
    
    if(root->data>val1&&root->data>val2){
        return getLCA(root->left,val1,val2);
    }
    
    int val1Ans = -1;
    int val2Ans = -1;
    if(val1 < root->data)
        val1Ans = getLCA(root->left,val1,val2);
    else
        val1Ans = getLCA(root->right,val1,val2);
    
    if(val2 < root->data)
        val2Ans = getLCA(root->left,val1,val2);
    else 
        val2Ans = getLCA(root->right,val1,val2);
    
    if(val1Ans==-1 && val2Ans==-1)
        return -1;
    else if(val1Ans==-1)
        return val2Ans;
    else if(val2Ans==-1)
        return val1Ans;
    else{
        return root->data;
    }
 
}

