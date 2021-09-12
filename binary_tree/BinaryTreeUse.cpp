#include<iostream>
#include<queue>
#include"BinaryTreeNode.h"

using namespace std;

void printTree(BinaryTreeNode<int> *root){
	if(root == NULL)
		return;
	cout<<root->data<<" :";
	if(root->left != NULL)
		cout<<" L "<<root->left->data;
	if(root->right != NULL)
		cout<<" R "<<root->right->data;
	cout<<endl;
	
	printTree(root->left);
	printTree(root->right);
}
BinaryTreeNode<int>* takeInput(){
	int rootData;
	cout<<"Enter data "<<endl;
	cin>>rootData;
	if(rootData == -1)
		return NULL;
		
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	
	BinaryTreeNode<int>*leftChild = takeInput();
	BinaryTreeNode<int>*rightChild = takeInput();
	
	root->left = leftChild;
	root->right = rightChild;
	
	return root;
}

int numberOfNode(BinaryTreeNode<int>* root){
	if(root == NULL)
		return 0;
	return 1 + numberOfNode(root->left) + numberOfNode(root->right);
}

BinaryTreeNode<int>* takeInputLevelWise(){
	int rootData;
	cout<<"Enter data "<<endl;
	cin>>rootData;
	if(rootData == -1)
		return NULL;
	
	BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
	
	queue<BinaryTreeNode<int>*> pendingNode;
	pendingNode.push(root);
	while(pendingNode.size() != 0){
		BinaryTreeNode<int>* front = pendingNode.front();
		pendingNode.pop();
		
		cout<<"Enter the left child of "<<front->data<<endl;
		int leftChild;
		cin>>leftChild;
		if(leftChild != -1){
		BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChild);
		front->left = child;
		pendingNode.push(child);		
		}
		cout<<"Enter the right child of "<<front->data<<endl;
		int rightChild;
		cin>>rightChild;
		if(rightChild != -1){
		BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChild);
		front->right = child;
		pendingNode.push(child);		
		}

	}
	return root;
}


int main(){
/*	BinaryTreeNode<int>*root = new BinaryTreeNode<int>(1);
	BinaryTreeNode<int>*node1 = new BinaryTreeNode<int>(2);
	BinaryTreeNode<int>*node2 = new BinaryTreeNode<int>(3);
	
	root->left = node1;
	root->right = node2;
	
	cout<<"Root"<<root->data<<endl;
	cout<<"left"<<node1->data<<endl;
	cout<<"right"<<node2->data<<endl;
*/
	BinaryTreeNode<int>* root = takeInputLevelWise();
	printTree(root);
}
