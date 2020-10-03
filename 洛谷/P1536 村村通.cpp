#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1005;
int parent[MAXN], N, M;

int find(int a) {
	int pa=parent[a], i=parent[a];
	while(parent[pa]!=pa) pa = parent[pa];
	while(a!=pa) {
		parent[a] = pa;
		a = i;
		i = parent[a];
	}
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
	while(scanf("%d", &N)==1 && N!=0) {
		scanf("%d", &M);
		int i, a, b, ans = N-1;
		for(i=1;i<=N;i++) parent[i] = i;
		for(i=1;i<=M;i++) {
			scanf("%d %d", &a, &b);
			if(Union(a, b)) ans--;
		}
		printf("%d\n", ans);
	}
}
