#include<iostream>
#include<cstdio>
#include<algorithm>
#define Max(a,b) (a>b?a:b)
using namespace std;
int N, M, parent[305], ans=0;
struct Edge{
	int u,v,c;
	Edge():u(0),v(0),c(0){}
	Edge(int u, int v, int c):u(u),v(v),c(c){}
	bool operator <(const Edge &a)const{
		return c<a.c;
	}
}edge[100005];

int find(int a) {
	int pa=a,i=parent[a];
	while(parent[pa] != pa) pa = parent[pa];
	while(i != pa) {
		i = parent[a];
		parent[a] = pa;
		a = i;
	}
	return pa;
}

bool Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if(pa==pb) return false;
	parent[pa] = pb;
	return true;
}

int main()
{
	scanf("%d %d", &N, &M);
	int i;
	for(i=1;i<=N;i++) parent[i] = i;
	for(i=0;i<M;i++) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].c);
	}
	sort(edge, edge+M);
	N--, i=0;
	printf("%d ", N);
	while(N>0) {
		if(Union(edge[i].u, edge[i].v)) {
			N--;
			ans = Max(ans, edge[i].c);
		}
		i++;
	}
	printf("%d", ans);
	return 0;
}
