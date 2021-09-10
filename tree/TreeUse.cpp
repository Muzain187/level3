#include<iostream>
#include<vector>
#include<queue>
#include "TreeNode.h"

using namespace std;

TreeNode<int> *takeInput(){
	int rootData;
	cout<<"Enter data ";
	cin>>rootData;
	
	TreeNode<int> *root = new TreeNode<int>(rootData);
	
	int n;
	cout<<"Enter no.of children";
	cin>>n;
	for(int i=0; i<n; i++){
		TreeNode<int> *child = takeInput();
		root->children.push_back(child); 
	}
	return root;
}
TreeNode<int>* tekeInputLevelWise(){
	int rootData;
	cout<<"Enter root data :";
	cin>>rootData;
	
	TreeNode<int>*root = new TreeNode<int>(rootData);
	queue<TreeNode<int>*> pendingNode;
	pendingNode.push(root);
	
	while(pendingNode.size() != 0){
		TreeNode<int>* front = pendingNode.front();
		pendingNode.pop();
		
		cout<<"Enter number of children of "<<front->data<<endl;
		int numchild;
		cin>>numchild;
		
		for(int i=0; i<numchild; i++){
			int chid;
			cout<<"Enter "<<i<<" th child of "<<front->data<<endl;
			cin>>childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push(child);
			pendingNode.push(child);
		}
	}
	return root;
}
void printDepth(TreeNode<int>* root,int k){
	if(root == NULL)
		return;
	if(k == 0){
		cout<<root->data<<endl;
		return;
	}
	for(int i=0; i<root->children.size(); i++)
		printDepth(root->children[i],k-1);
}

void printTree(TreeNode<int> *root){
	if(root == NULL)
		return;
	
	cout<<root->data<<" :";
	for(int i=0; i<root->children.size(); i++){
		cout<<root->children[i]->data<<" ,";
	}
	cout<<endl;
	for(int i=0; i<root->children.size(); i++)
		printTree(root->children[i]);
}

int main(){
	TreeNode <int> *root = takeInput();
	printTree(root);
	printDepth(root,3);
	return 0;
}


