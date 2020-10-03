#include<iostream>
#include<cstdio>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 32000+5;
int head[MAXN], A[MAXN], val[MAXN], N, parent[MAXN], cnt=0, ans = -0x3f3f3f3f;
struct Edge{
	int to, next;
}edge[MAXN];

void add(int a, int b) {  //链式前向星建图 
	edge[++cnt].to = b;
	edge[cnt].next = head[a];
	head[a] = cnt;
}

void dfs(int u, int f) {  //u为儿子  f为双亲 
	for(int i=head[u];i!=0;i=edge[i].next) {
		if(edge[i].to != f) {
			dfs(edge[i].to, u);
			val[u] += Max(0, val[edge[i].to]);
		}
	}
	ans = Max(ans, val[u]);
}

int main()
{
	int i, a, b;
	cin>>N;
	for(i=1;i<=N;i++) {
		scanf("%d", &A[i]);
		val[i] = A[i];
	}
	for(i=1;i<N;i++) {
		scanf("%d %d", &a, &b);
		add(a, b), add(b, a);
	}
	dfs(1, 0);
	cout<<ans;
	return 0;
}
