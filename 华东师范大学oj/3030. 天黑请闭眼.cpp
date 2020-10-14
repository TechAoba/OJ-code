#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T, M, K;

struct Node{
	int val;
	Node *next;
	Node(int val):val(val),next(NULL){}
};
Node *head;

void solve() {
	head = new Node(-1);
	Node *rear = head;
	int i;
	for(i=1;i<=M;i++) {
		rear->next = new Node(i);
		rear = rear->next;
	}
	rear->next = head;
	Node *now = head;
	int cnt = M-1;
	while(cnt--) {
		for(i=1;i<K;i++) {
			if(now->next==head) now = now->next->next;
			else now = now->next;
		}
		//删除后面的节点
		if(now->next==head) {  //头节点 
			//printf("  删除%d\n", head->next->val);
			head->next = head->next->next;
			now = head;
		} 
		else{
			//printf("删除%d\n", now->next->val);
			now->next = now->next->next;
		}
	}
	printf("%d\n", head->next->val);
}

int main()
{
	int kase = 0;
	scanf("%d", &T);
	for(;kase<T;kase++) {
		scanf("%d %d", &M, &K);
		printf("case #%d:\n", kase);
		solve();
	}
	return 0;
 } 
