#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 205;
int N, M, head[MAXN], cnt, dp[MAXN][MAXN], val[MAXN];  //dp[i][j]为i节点攻占j个城堡的最大收益
bool vis[MAXN];

struct Edge{
	int to, Next;
}edge[MAXN];

void Init() {
	//memset(vis, 0, sizeof(vis));
	memset(dp, 0, sizeof(dp));
	memset(head, 0, sizeof(head));
	cnt = 0;
} 

void add(int a, int b) {
	edge[++cnt].to = b;
	edge[cnt].Next = head[a];
	head[a] = cnt;
} 

void TreeDp(int u) {
	//vis[u] = 1;
	int i, j, k;
	for(i=1;i<=M;i++) dp[u][i] = val[u];
	for(i=head[u];i!=0;i=edge[i].Next) {
		int to = edge[i].to;
		TreeDp(to);
		for(j=M;j>1;j--) {
			for(k=0;k<=j-1;k++) {
				dp[u][j] = Max(dp[u][j], dp[u][j-k]+dp[to][k]);
			}
		}
	}
}

int main()
{
	while(scanf("%d %d", &N, &M) != EOF) {
		if(N==0 && M==0) break;  //以0为根节点,算上0点M要加1 
		Init();
		int i, poi;
		for(i=1;i<=N;i++) {
			scanf("%d %d", &poi, &val[i]);
			add(poi, i);
		}
		if(M==0) {
			printf("0\n");
			continue;
		}
		M++;
		TreeDp(0);
		printf("%d\n", dp[0][M]);
	}
	return 0;
}
