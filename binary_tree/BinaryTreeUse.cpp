#include<iostream>
#include<queue>
#include"BinaryTreeNode.h"

using namespace std;

//build binary tree from inorder and preorder
BinaryTreeNode<int>* buildTree(int *preorder,int *inorder,int ps,int pe,int ins,int ine){
    if(ps > pe)
        return NULL;
    
    int rootData = preorder[ps];
    int rootIndex = -1;
    for(int i=ins; i<=ine; i++){
        if(inorder[i] == rootData){
            rootIndex = i;
            break;
        }
    }
    
    //finding left indexes
    int lIns = ins;
    int lIne = rootIndex-1;
    int lPres = ps+1;
    int lPree = lIne - lIns + lPres;
    
    // finding right indexes
    int rIns = rootIndex+1;
    int rIne = ine;
    int rPres = lPree + 1;
    int rPree = pe;
    
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTree(preorder,inorder,lPres,lPree,lIns,lIne);
    root->right = buildTree(preorder,inorder,rPres,rPree,rIns,rIne);
    
    return root;
}


BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    return buildTree(preorder,inorder,0,preLength-1,0,inLength-1);
}

//build binary tree from inorder and postorder
BinaryTreeNode<int>* buildTree(int *inorder,int *postorder,int inS,int inE,int postS,int postE){
    if(postS > postE || inS > inE)
        return NULL;
    
    int rootData = postorder[postE];
    int rootindex = -1;
    for(int i=inS; i<=inE; i++){
        if(inorder[i] == rootData){
            rootindex = i;
            break;
        }
    }
    
    //left 
    int LinS = inS;
    int LinE = rootindex - 1;
    int LpostS = postS;
    int LpostE = LinE - LinS + LpostS;
    
    //right
    int RinS = rootindex + 1;
    int RinE = inE;
    int RpostS = LpostE + 1;
    int RpostE = postE-1;
    
    BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootData);
    root->left = buildTree(inorder,postorder,LinS,LinE,LpostS,LpostE);
    root->right = buildTree(inorder,postorder,RinS,RinE,RpostS,RpostE);
    
    return root;
}


BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return buildTree(inorder,postorder,0,inLength-1,0,postLength-1);
}



void postOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL)
        return;
    
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    
}
void preOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL)
        return;
    preOrder(root->left);
    cout<<root->data<<" ";
    preOrder(root->right);
}


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
