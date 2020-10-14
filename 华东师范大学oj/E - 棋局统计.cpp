#include<iostream>
#include<cstdio>
#include<stack>
#include<vector>
#define res register int
#include<cstring>
using namespace std;
const int MAXM = 250005, MAXN = 50005;
int N, M, parent[MAXN], num=0, head[MAXN], ru[MAXN], chu[MAXN];
bool vis[MAXN];
vector<int> V;

struct Edge{
	int to, Next;
}edge[MAXM];

void add(int a, int b) {
	num++;
	edge[num].to = b;
	edge[num].Next = head[a];
	head[a] = num;
}

struct Node{
	int a, b;
}node[MAXM];

int find(int a) {
	if(parent[a]!=a) parent[a] = find(parent[a]);
	return parent[a];
}

void Union(int a, int b) {
	int pa = find(a), pb = find(b);
	if(pa==pb) return;
	parent[pa] = pb;
}

int main()
{
	scanf("%d %d", &N, &M);
	res i;
	for(i=0;i<N;i++) parent[i] = i;
	char op;
	int pa, pb, cnt=0, a, b, to;
	for(i=0;i<M;i++) {
		scanf("%d %c %d", &a, &op, &b);
		if(op=='>') {
			node[cnt].a = a;
			node[cnt++].b = b;
		}
		if(op=='=') {
			Union(a, b);
		}
	}
	M = cnt;
	for(i=0;i<N;i++) {
		pa = find(i);
		if(!vis[pa]) {
			vis[pa] = 1;
			V.push_back(pa);
		}
	}
	cnt = V.size();
	for(i=0;i<M;i++) {
		pa = find(node[i].a), pb = find(node[i].b);
		chu[pa]++, ru[pb]++;
		add(pa, pb);
	}
	stack<int> S;
	for(i=0;i<V.size();i++) {
		if(ru[V[i]]==0) S.push(V[i]);
	}
	while(!S.empty()) {
		int t = S.top(); S.pop(); cnt--;
		for(i=head[t];i!=0;i=edge[i].Next) {
			to = edge[i].to;
			ru[to]--;
			if(ru[to]==0) S.push(to);
		}
	}
	if(cnt==0) printf("consistent\n");
	else printf("inconsistent\n");
	return 0;
}
