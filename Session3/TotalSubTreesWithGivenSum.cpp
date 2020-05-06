#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char a[1000];
vector<int> v;

class node{
public:
	int data;
	node* left,*right;
	
	node(int d){
		data = d;
		left =right = NULL;
	}
};

void StringToInt(){
	char *ans = strtok(a," ");
	while(ans!=NULL){
		v.push_back(stoi(ans));
		ans = strtok(NULL," ");
	}
}

node* CreateTree(){
	if(strlen(a) == 0 || v.size()==0) return NULL;

	int no = v[0];
	node* root = new node(no);
	int i = 1;
	queue<node*> q;
	q.push(root);

	while(!q.empty() && i<v.size()){
		node* temp = q.front();
		q.pop();
		no = v[i++];
		temp->left = new node(no);
		q.push(temp->left);
		if(i>=v.size()){
			break;
		}

		no = v[i++];
		temp->right = new node(no);
		q.push(temp->right);
		if(i>=v.size()) break;

	}
	return root;
}

int Sum(node* root){
	if(root == NULL) return 0;

	int leftSum = Sum(root->left);
	int rightSum = Sum(root->right);
	return root->data+leftSum+rightSum;
}

int CountSubtrees(node* root,int x){
	if(root == NULL) return 0;
	int ans = 0 ;
	if(Sum(root) == x){
		ans = 1;
	}

	int left_Subtrees = CountSubtrees(root->left,x);
	int right_Subtrees = CountSubtrees(root->right,x);
	return ans + left_Subtrees + right_Subtrees;
}


int main(){
	int t,x;
	cin>>t;
	while(t--){
		cin.ignore();
		cin.getline(a,1000);
		StringToInt();
		cin>>x;
		node* root = CreateTree();
		cout<<CountSubtrees(root,x)<<endl;
	}
	return 0;
}