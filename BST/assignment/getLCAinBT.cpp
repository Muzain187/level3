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



int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
    if(root == NULL)
        return -1;
    
    if(root->data == a)
        return a;
    if(root->data == b)
        return b;
    
    int leftAns = getLCA(root->left,a,b);
    int rightAns = getLCA(root->right,a,b);
    
    if(leftAns==-1 && rightAns==-1)
        return -1;
    else if(leftAns==-1)
        return rightAns;
    else if(rightAns==-1)
        return leftAns;
    else{
        return root->data;
    }

}









/*
bool getPath(BinaryTreeNode<int>* root,int key,vector<int>& v){
    
    if(root == NULL){
        v.pop_back();
        return false;
    }
	v.push_back(root->data);
    
     if(root->data == key)
        return true;
    else 
        return ( getPath(root->left,key,v) || getPath(root->right,key,v) );
}



    
    if(a == root->data)
        return root->data;
    if(b == root->data)
        return root->data;
    
    vector<int> v1,v2;
    int pc=0;
    
    
    if(getPath(root,a,v1) && getPath(root,b,v2)){    
        while(v1.at(pc) == v2.at(pc)){
            if(a==b)
                return v1[pc];
            pc++;
        }
        return v1.at(pc);
    }
    return -1;
*/
