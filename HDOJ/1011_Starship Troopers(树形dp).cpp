#include<iostream>
#include<cstdio>
#include<cstring>
#define res register int 
#define Max(a, b) (a>b?a:b)
using namespace std;
const int MAXN = 150;
int dp[MAXN][MAXN], N, M, cnt, head[MAXN];  //N个点 M个兵力  dp[i][j] 代表i点用j个兵力最多可以得到的val
int bug[MAXN], val[MAXN];
bool vis[MAXN]; 

struct Edge{
	int to, Next;
}edge[MAXN*2];

void add(int a, int b) {
	edge[++cnt].to = b;
	edge[cnt].Next = head[a];
	head[a] = cnt;
}

void Init() {  //初始化 
	memset(dp, 0, sizeof(dp));
	memset(head, 0, sizeof(head));
	memset(vis, 0, sizeof(vis));
	cnt = 0;
}

void TreeDp(int u) {  //以u为起点 
	vis[u] = true;
	int need = (bug[u]+19)/20;  //起点需要的兵力
	if(need>M) return;
	res i, j, k;
	for(i=need;i<=M;i++) dp[u][i] = val[u];
	for(i=head[u];i!=0;i=edge[i].Next) {
		int to = edge[i].to;  //子节点
		if(vis[to] || head[to]==0) continue;
		TreeDp(to);
		for(j=M;j>need;j--) {
			for(k=0;k<=j-need;k++) {
				dp[u][j] = Max(dp[u][j], dp[u][j-k] + dp[to][k]);
			}
		}
	} 
	if(dp[u][0]>0)
    {
        dp[u][1]=Max(dp[u][1],dp[u][0]);
        dp[u][0]=0;
    }
}

int main()
{
	res i;
	int a, b;
	while(scanf("%d %d", &N, &M)!=EOF) {
		if(N==-1) break;
		Init();
		for(i=1;i<=N;i++) scanf("%d %d", &bug[i], &val[i]);
		for(i=1;i<N;i++) {
			scanf("%d %d", &a, &b);
			add(a, b); add(b, a);
		}
		if(M==0) {
			printf("0\n");
			continue;
		}
		TreeDp(1);
		printf("%d\n", dp[1][M]);
	}
	return 0;
}
