#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* left,*right;
	node(int d){
		data = d;
		left = right =NULL;
	}
};

node* CreateTree(){
	int data;
	cin>>data;
	if((data) == -1) return NULL;
	node* root = new node(data);
	root->left = CreateTree();
	root->right = CreateTree();
	return root;
}

node* FindNode(node* root,int x){
	// Base case
	if(root == NULL) return NULL;

	// Recursive case
	if(root->data == x) return root;
	node* left = FindNode(root->left,x);
	node* right = FindNode(root->right,x);
	// if(left == NULL) return right;
	// else return left;
	return (left==NULL?right:left);
}

int CountNodes(node* root){
	if(root == NULL) return 0;

	int left_nodes_count = CountNodes(root->left);
	int right_nodes_count = CountNodes(root->right);
	return 1+left_nodes_count+right_nodes_count;
}

int BigBang(node* root,int x,int n){
	// Find the node of rajesh
	node* t = FindNode(root,x);

	int left = CountNodes(t->left);
	int right =CountNodes(t->right);
	int remaining = n-(left+right)-1;

	if(left>right+remaining) return 1;
	if(right>left+remaining) return 1;
	if(remaining>left+right) return 1;
	return 0;
}


int main(){
	int N,n,x; // n->Actual number of nodes in the tree
	cin>>N>>n>>x;

	node* root = CreateTree();

	cout<<BigBang(root,x,n)<<endl;
	return 0;
}












