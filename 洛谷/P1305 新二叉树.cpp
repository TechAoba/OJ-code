#include<iostream>
#include<string>
using namespace std;
int N;
struct Node{
	char ch;
	Node *left, *right, *father;
}nodes[100];
Node *root;

void dfs(Node *R) {
	if(R==NULL) return;
	cout<<R->ch;
	dfs(R->left);
	dfs(R->right);
}

int main()
{
	int i;
	string S;
	cin>>N;
	for(i=0;i<N;i++) {
		cin>>S;
		nodes[S[0]-'A'].ch = S[0];
		if(S[1]!='*') {
			nodes[S[0]-'A'].left = &nodes[S[1]-'A'];
			nodes[S[1]-'A'].father = &nodes[S[0]-'A'];
			nodes[S[1]-'A'].ch = S[1];
		}
		if(S[2]!='*') {
			nodes[S[0]-'A'].right = &nodes[S[2]-'A'];
			nodes[S[2]-'A'].father = &nodes[S[0]-'A'];
			nodes[S[2]-'A'].ch = S[2];
		}
	}
	root = &nodes[S[0]-'A'];
	while(root->father!=NULL) root = root->father;
	dfs(root);
	return 0;
}
