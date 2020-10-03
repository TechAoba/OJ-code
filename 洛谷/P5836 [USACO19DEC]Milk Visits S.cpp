#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int MAXN = 1e5+10;
int N, M, T, head[MAXN], cnt=0, H[MAXN], G[MAXN], deep[MAXN], dp[MAXN][20];
char S[MAXN];
struct Edge{
	int to, Next;
}edge[MAXN*2];

void add(int a, int b) {
	edge[++cnt].to = b;
	edge[cnt].Next = head[a];
	head[a] = cnt;
}

void dfs(int u, int fa) {
	deep[u] = deep[fa]+1;
	dp[u][0] = fa;
	if(S[u]=='H') H[u] = 1;
	else G[u] = 1;
	H[u] += H[fa]; G[u] += G[fa];
	for(int i=1;i<=T;i++) dp[u][i] = dp[dp[u][i-1]][i-1];
	for(int i=head[u];i!=0;i=edge[i].Next) {
		if(edge[i].to!=fa) dfs(edge[i].to, u);
	}
}

int LCA(int a, int b) {
	if(deep[a]<deep[b]) swap(a, b);
	for(int i=T;i>=0;i--) {
		if(deep[dp[a][i]] >= deep[b]) a = dp[a][i];
	}
	if(a==b) return a;
	for(int i=T;i>=0;i--) {
		if(dp[a][i] != dp[b][i]) a=dp[a][i],b=dp[b][i];
	}
	return dp[a][0];
}

int main()
{
	scanf("%d %d", &N, &M);
	scanf("%s", S+1);
	int i, a, b;
	for(i=1;i<N;i++) {
		scanf("%d %d", &a, &b);
		add(a, b); add(b, a);
	}
	T = (int)log2(N);
	dfs(1, 0);  //以节点1为父节点 
	char ch;
	for(i=1;i<=M;i++) {
		scanf("%d %d %c", &a, &b, &ch);
		int lca = LCA(a,b);
		if(ch=='H' && H[a]+H[b]-H[lca]-H[dp[lca][0]]>0) printf("1");
		else if(ch=='G' && G[a]+G[b]-G[lca]-G[dp[lca][0]]>0) printf("1");
		else printf("0");
	}
	putchar('\n');
	return 0;
 } 
