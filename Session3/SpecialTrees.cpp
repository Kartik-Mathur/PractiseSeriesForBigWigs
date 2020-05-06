#include <iostream>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;
	node(int d){
		data = d;
		left = right = NULL;
	}
};

void inorder(node* root){
	if(root ==NULL) return;
	
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

node* SpecialTrees(int *a,int s,int e){
	// Base case
	if(s>e) return NULL;

	int k = s;
	for(int i = s;i<=e;i++){
		if(a[i]>a[k]){
			k = i;
		}
	}
	node* root = new node(a[k]);
	root->left = SpecialTrees(a,s,k-1);
	root->right = SpecialTrees(a,k+1,e);
	return root;
}

int main(){
	int n;
	cin>>n;

	int * a = new int[n];
	for(int i=0;i<n;i++)cin>>a[i];

	node* root = SpecialTrees(a,0,n-1);
	inorder(root);

	return 0;
}












