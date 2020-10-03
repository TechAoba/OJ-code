#include<stdio.h>
const int maxn = 105;
struct Node{
	int id;
	Node *front, *next;
}nodes[maxn];
int N, M;

void Dele(Node *cur) {
	cur->front->next = cur->next;
	cur->next->front = cur->front;
}

int main()
{
	scanf("%d%d", &N, &M);
	Node *now = &nodes[1];
	int i, cnt = 1;
	nodes[1].id = 1; nodes[1].front = &nodes[N]; nodes[1].next = &nodes[2];
	nodes[N].id = N; nodes[N].front = &nodes[N-1]; nodes[N].next = &nodes[1];
	for(i=2;i<N;i++) {
		nodes[i].id = i; nodes[i].front = &nodes[i-1]; nodes[i].next = &nodes[i+1];
	}
	for(i=1;i<=N;i++) {
		while(cnt<M) {
			now = now->next;
			cnt++;
		}
		printf("%d ", now->id); 
		Dele(now);
		cnt = 0;
	}
	return 0;
}
