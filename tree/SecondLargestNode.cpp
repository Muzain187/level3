#include<bits/stdc++.h>
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root==NULL)
        return NULL;
    queue<TreeNode<int>*> q;
    
    q.push(root);
    
    int l=INT_MIN,s=INT_MIN;
    
    TreeNode<int>* sec=NULL,*lar=NULL;
    
    while(!q.empty()){
        TreeNode<int>*front=q.front();
        q.pop();
        if(front->data>l){
            s=l;
            sec=lar;
            l=front->data;
            lar=front;
        }
        if(front->data<l&&front->data>s){
            s=front->data;
            sec=front;
        }
        for(int i=0;i<front->children.size();i++)
            q.push(front->children[i]);
    }
    return sec;
}

