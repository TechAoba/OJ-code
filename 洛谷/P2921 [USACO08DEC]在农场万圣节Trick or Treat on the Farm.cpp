#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 100005;
int parent[MAXN], len[MAXN], N, to[MAXN], ans[MAXN];  //len 表示节点到树顶的距离 

int find(int a) {
	if(parent[a] != a) {
		int pa = parent[a];
		parent[a] = find(pa);
		len[a] += len[pa];
	}
	return parent[a];
}

int go1(int a) {
	if(ans[a]!=0) return ans[a];
	ans[a] = go1(to[a])+1;
	return ans[a];
}

void point(int a, int b) {
	int pa = find(a), pb = find(b);
	if(pa!=pb) {  //不连通 
		parent[a] = pb;
		len[a] = len[b]+1;
		if(ans[pb] != 0) go1(a);
	}
	else {  //联通 
		int T = len[b] + 1;
		for(int i=b;i!=a;i=to[i]) {
			ans[i] = T;
		}
		ans[a] = T;
	}
}

int main()
{
	int i;
	scanf("%d", &N);
	for(i=1;i<=N;i++) parent[i] = i;
	for(i=1;i<=N;i++) {
		scanf("%d", &to[i]);
		if(to[i]==i) ans[i] = 1;
		else point(i, to[i]);
	}
	for(i=1;i<=N;i++) {
		if(!ans[i]) go1(i);
	}
	for(i=1;i<=N;i++) printf("%d\n", ans[i]);
	return 0;
}
