#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define res register int
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 3005, FINF = -0x3f3f3f3f;
int N, M, earn[MAXN], dp[MAXN][MAXN], num[MAXN]={0};
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

struct Node{
	int id, cost;
	Node(int id, int cost):id(id),cost(cost){}
};
vector<Node> V[MAXN];

int dfs1(int a) {  //计算子树的叶子数量 
	int ans = 0;
	for(register int i=0;i<V[a].size();i++) {
		if(num[V[a][i].id]!=0) ans += num[V[a][i].id];
		else ans += dfs1(V[a][i].id);
	}
	return num[a] = ans;
}

void dfs(int a) {
	if(a>N-M) return;
	int cnt = 0;
	res j, k;
	for(res i=0;i<V[a].size();i++) {
		int v = V[a][i].id, cost = V[a][i].cost;
		cnt += num[v];
		dfs(v);
		for(k=cnt;k>=0;k--) {
			for(j=1;j<=num[v] && j<=k;j++) {
				dp[a][k] = Max(dp[a][k], dp[a][k-j]+dp[v][j]-V[a][i].cost);
			}
		}
	}
}

int main()
{
	N = read(), M=read();
	res i, j;
	for(i=1;i<=N;i++) {
		for(j=1;j<=M;j++) dp[i][j] = FINF;
	}
	int r = N-M, cnt, id, cost, val;
	for(i=1;i<=r;i++) {
		cnt = read();
		for(j=0;j<cnt;j++) {
			id = read(), cost = read();
			V[i].push_back(Node(id, cost));
		}
	}
	for(i=N-M+1;i<=N;i++) earn[i] = read(), dp[i][1] = earn[i], num[i]=1;
	if(!num[1]) dfs1(1);
	dfs(1);
	for(i=M;i>0;i--) {
		if(dp[1][i]>=0) {
			printf("%d\n", i);
			break;
		}
	}
	return 0;
 } 
