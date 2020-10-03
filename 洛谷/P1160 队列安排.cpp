#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 100000+10;
bool vis[maxn];
int N;
struct Node{
	int id;
	Node *front, *next;
}nodes[maxn];



int main()
{
	Node *cur = &nodes[1];
	cin>>N;
	int i, j, k, oper, M;
	nodes[1].id = 1;
	for(i=2;i<=N;i++) {
		nodes[i].id = i;
		scanf("%d %d", &k, &oper);
		if(oper==0) {  //²åµ½kµÄ×ó±ß 
			nodes[i].front = nodes[k].front;
			nodes[i].next = &nodes[k];
			if(nodes[k].front!=NULL) nodes[k].front->next = &nodes[i];
			nodes[k].front = &nodes[i];
			if(cur->id == k) cur = cur->front;
		}
		else {
			nodes[i].front = &nodes[k];
			nodes[i].next = nodes[k].next;
			if(nodes[k].next!=NULL) nodes[k].next->front = &nodes[i];
			nodes[k].next = &nodes[i];
		}
	}
	cin>>M;
	for(i=0;i<M;i++) {
		scanf("%d", &j);
		if(vis[j]) continue;
		if(cur->id == j) cur = cur->next;
		vis[j] = true;
		if(nodes[j].front!=NULL) nodes[j].front->next = nodes[j].next;
		if(nodes[j].next!=NULL) nodes[j].next->front = nodes[j].front;
	}
	while(cur!=NULL) {
		printf("%d ", cur->id);
		cur = cur->next;
	}
	return 0;
}
