#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Max(a,b) (a>b?a:b)
#define res register int 
using namespace std;
int A[105][105], N, K, dp[105][105];
bool vis[105][105];
struct Node{
	int r, c, val;
	bool operator<(const Node &a)const{
		return val>a.val;
	}
}node[105*105];

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

inline int read() {
	int x=0, f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
} 

int dfs(int r, int c) {
	res i, j, k, nr, nc;
	if(vis[r][c]) return dp[r][c];
	vis[r][c] = true;
	int ans=0;
	for(j=0;j<4;j++) {
		for(k=1;k<=K;k++) {
			nr = r+dr[j]*k;
			nc = c+dc[j]*k;
			if(nr<1||nr>N||nc<1||nc>N) break;
			if(A[nr][nc]>A[r][c]) ans = Max(ans, dfs(nr, nc));
		}
	}
	return dp[r][c] = dp[r][c] + ans;
}

int main()
{
	while(scanf("%d %d", &N, &K) == 2) {
		memset(vis, 0, sizeof(vis));
		res r, c, nr, nc, cnt=0, i, j, k;
		for(r=1;r<=N;r++) {
			for(c=1;c<=N;c++) {
				A[r][c] = read();
				//node[cnt].r = r;
				//node[cnt].c = c;
				//node[cnt++].val = A[r][c];
				dp[r][c] = A[r][c];
			}
		}
		printf("%d\n", dfs(1, 1));
	}
	return 0;
}
