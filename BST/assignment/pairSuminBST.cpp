/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
#include<bits/stdc++.h> 

vector<int> arr;

void inorder(BinaryTreeNode<int> *root){
    if(root == NULL)
        return;
    inorder(root->left);
    arr.push_back(root->data);
    inorder(root->right);
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    // Write your code here
    inorder(root);
    int i=0,j=arr.size()-1;
    while(i < j){
        int sum = arr[i] + arr[j];
        if(sum == s){
            cout<<arr[i]<<" "<<arr[j]<<endl;
         	i++;
            j--;
        }
        else if(sum > s)
            j--;
        else
            i++;
    }
}
