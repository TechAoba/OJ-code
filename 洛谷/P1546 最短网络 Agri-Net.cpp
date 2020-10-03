#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int parent[105], ans=0;

struct Edge{
	int u, v, len;
	Edge():u(0),v(0),len(0){}
	Edge(int u,int v,int len):u(u),v(v),len(len){}
	bool operator <(const Edge &a)const{
		return len<a.len;
	}
}edge[10005];

int find(int a) {
	int pa=a, i=parent[a];
	while(parent[pa]!=pa) pa=parent[pa];
	while(i!=pa) {
		i=parent[a];
		parent[a] = pa;
		a = i;
	}
	return pa;
}

bool Union(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if(pa==pb) return false;  //本身是并集
	parent[pa] = pb;
	return true; 
}

int main()
{
	int i, j, N, a, cnt=1;
	scanf("%d", &N);
	for(i=1;i<=N;i++) {
		parent[i] = i;
	}
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			scanf("%d", &a);
			if(j>i) edge[cnt++] = Edge(i, j, a);
		}
	}
	sort(edge+1, edge+cnt);
	i=1;
	N--;
	while(N>0) {
		if(Union(edge[i].u, edge[i].v)) {  //连接成功 
			N--;
			ans+=edge[i].len;
		}
		++i;
	}
	cout<<ans<<endl;
	return 0;
}
