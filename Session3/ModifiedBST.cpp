#include <iostream>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;
	node(int d):data(d),left(NULL),right(NULL){

	}
};

node* CreateTree(){
	int data;
	cin>>data;
	if(data == -1) return NULL;
	node* root = new node(data); // What ever the first node/data I will make it root node
	root->left = CreateTree();
	root->right = CreateTree();
	return root;
}

void preorder(node* root){
	if(root==NULL){
		return;
	}

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void ModifyBST(node* root,int &sum){
	// Base case
	if(root == NULL) return;

	ModifyBST(root->right,sum);
	sum+=root->data;
	root->data = sum;
	ModifyBST(root->left,sum);
}

int main(){
	node* root = NULL;
	root = CreateTree();
	int sum = 0;
	ModifyBST(root,sum);
	preorder(root);
	
	return 0;
}
