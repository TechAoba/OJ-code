#include<iostream>
#include<cstdio>
#include<cstring>
#include<stack>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
const int MAXN = 1e4+10, MAXM = 1e5+10;
int ans = 0, N, M, val[MAXN], head[MAXN], head1[MAXN], cnt=0, que[MAXN], top=0;
int dfn[MAXN], low[MAXN], timeVal=0, ID=0, team[MAXN], ru[MAXN], dp[MAXN], Ans[MAXN];
bool inStack[MAXN];

struct Edge{
	int to, Next;
}edge[MAXM], ed[MAXM];

void add(int a, int b) {
	edge[++cnt].to = b;
	edge[cnt].Next = head[a];
	head[a] = cnt; 
} 

void add1(int a, int b) {
	ed[++cnt].to = b;
	ed[cnt].Next = head1[a];
	head1[a] = cnt; 
} 

void tarjan(int u) {
	dfn[u] = low[u] = ++timeVal;
	que[top++] = u;
	inStack[u] = true;  //入栈 
	int i;
	for(i=head[u];i!=0;i=edge[i].Next) {
		int to = edge[i].to;
		if(!dfn[to]) {  //未访问过 
			tarjan(to);
			low[u] = Min(low[u], low[to]);
		}
		else if(inStack[to]) {
			low[u] = Min(low[u], dfn[to]);
		}
	}
	if(low[u]==dfn[u]) {  //为极大连通图的父节点 
		ID++;
		while(i = que[--top]){//出栈 
			inStack[i] = false;
			team[i] = ID;
			if(i==u) break;
			val[u] += val[i];
		}
		Ans[ID] = dp[ID] = val[u];  //只包含极大连通图 
		ans = Max(ans, Ans[ID]);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	int i, j, a, b, to;
	for(i=1;i<=N;i++) scanf("%d", &val[i]);
	for(i=0;i<M;i++) {
		scanf("%d %d", &a, &b);
		add(a, b);
	}
	for(i=1;i<=N;i++) if(!dfn[i]) tarjan(i);
	cnt = 0;
	for(i=1;i<=N;i++) {
		for(j=head[i];j!=0;j=edge[j].Next) {
			to = edge[j].to;
			if(team[i] != team[to]) add1(team[i], team[to]), ru[team[to]]++;
		}
	}
	stack<int> S;
	for(i=1;i<=ID;i++) {
		if(ru[i] == 0) S.push(i);
	}
	while(!S.empty()) {
		int u = S.top(); S.pop();
		for(i=head1[u];i!=0;i=ed[i].Next) {
			to = ed[i].to;
			dp[to] = Max(dp[to], dp[u] + Ans[to]);
			ans = Max(ans, dp[to]);
			ru[to]--;
			if(ru[to]==0) S.push(to);
		}
	}
	printf("%d\n", ans);
	return 0;
}
