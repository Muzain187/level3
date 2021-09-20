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
void rootToLeafSumToK(BinaryTreeNode<int>* root,int k,vector<int>&v){
    if(root == NULL)
        return;
    int sum=0;
    for(int i=0;i<v.size(); i++)
        sum += v.at(i);
    sum += root->data;
    
    v.push_back(root->data);
    if(sum == k){
        if(root->left==NULL && root->right==NULL){
            for(int i=0; i<v.size(); i++)
                cout<<v[i]<<" ";
            cout<<endl;
        }
    }
    
    rootToLeafSumToK(root->left,k,v);
    rootToLeafSumToK(root->right,k,v);
    v.pop_back();
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    // Write your code here
    vector<int> v;
    rootToLeafSumToK(root,k,v);
  
}
