#include<iostream>
#include<cstdio>
#include<cstring>
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 1e4+10, MAXM = 5e4+10;
int N, M, cnt=0, head[MAXN], top=0, que[MAXN], dfn[MAXN], low[MAXN], timeVal=0, team[MAXN], ID=0, chu[MAXN], num[MAXN];
bool inStack[MAXN];
struct Edge{
	int to, Next;
}edge[MAXM];

void add(int a, int b) {
	edge[++cnt].to = b;
	edge[cnt].Next = head[a];
	head[a] = cnt;
}

void tarjan(int u) {
	dfn[u] = low[u] = ++timeVal;
	que[++top] = u;
	inStack[u] = true;
	for(int i=head[u];i!=0;i=edge[i].Next) {
		int to = edge[i].to;
		if(!dfn[to]) {
			tarjan(to);
			low[u] = Min(low[u], low[to]);
		}
		else if(inStack[to]) low[u] = Min(low[u], dfn[to]);
	}
	if(dfn[u] == low[u]) {
		int x, ans=0;
		ID++;
		while(x = que[top--]) {
			ans++;
			inStack[x] = false;
			team[x] = ID;
			if(x==u) break;
		}
		num[ID] = ans;  //第ID队伍的成员数量 
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	int i, j, a, b;
	for(i=1;i<=M;i++) {
		scanf("%d %d", &a, &b);
		add(a, b);
	}
	for(i=1;i<=N;i++) if(!dfn[i]) tarjan(i);
	for(i=1;i<=N;i++) {
		for(j=head[i];j!=0;j=edge[j].Next) {
			int to = edge[j].to;
			if(team[i]!=team[to]) chu[team[i]]++;
		}
	}
	int add = 0, ans;
	for(i=1;i<=ID;i++) {
		if(!chu[i]) ans = num[i], add++;
	}
	if(add!=1) puts("0");
	else printf("%d\n", ans);
	return 0;
}
