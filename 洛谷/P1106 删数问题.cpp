#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

typedef struct Node{
	int val;
	Node *Next;
}*TNode;

TNode Head, Rear;  //头节点 尾节点 

void show() {
	TNode p = Head->Next;
	while(p!=NULL && p->val==0) p=p->Next;
	if(p==NULL) {
		printf("0\n");
		return;
	}
	while(p!=NULL) {
		printf("%d", p->val);
		p = p->Next; 
	}
}

int main()
{
	Head = new Node();
	Head->Next = NULL;
	Rear = Head;
	int i, M, t=0;
	char T[255];
	scanf("%s %d", T, &M);
	int len = strlen(T);
	for(i=1;i<=len;i++) {
		TNode p = new Node();
		p->Next = NULL;
		p->val = T[i-1] ^ 48;
		Rear->Next = p;
		Rear=p;
	}
	while(M--) {
		TNode p = Head;
		bool ok = 0;
		while(p->Next->Next!=NULL) {
			if(p->Next->val > p->Next->Next->val) {
				p->Next = p->Next->Next;
				ok = 1;
				break;
			}
			p = p->Next;
		}
		if(!ok) {
			p->Next = NULL;
		}
		/*printf("第%d次删除:", ++t);
		show();
		puts(" ");*/
	}
	if(Head->Next==NULL) printf("0\n");
	else show();
	return 0;
}
