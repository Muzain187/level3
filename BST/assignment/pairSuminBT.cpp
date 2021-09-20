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
#include <bits/stdc++.h>
vector<int> arr;

void inorder(BinaryTreeNode<int> *root){
    if(root == NULL)
        return;
    inorder(root->left);
    arr.push_back(root->data);
    inorder(root->right);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	if(root == NULL)
        return;
    
  	inorder(root);
    
    sort(arr.begin(),arr.end());
    
    int i=0,j=arr.size()-1;
    while(j > i){
        int addition = arr[i] + arr[j];
        if(addition < sum)
            i++;
        else if(addition > sum)
            j--;
        else{
            cout<<arr[i]<<" "<<arr[j]<<endl;
            i++;
            j--;
        }
    }
    
}
