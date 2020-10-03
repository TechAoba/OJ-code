#include<cstdio>
#include<iostream>
#define Max(a,b) (a>b?a:b)
#include<cstring>
using namespace std;
const int MAXN = 6005, FINF = -0x3f3f3f3f;
int A[MAXN], head[MAXN], cnt=0, N, dp[MAXN][2], ans=-128;
struct Edge{
	int to, Next;
}edge[MAXN];

void add(int a, int b) {
	edge[++cnt].to = b;
	edge[cnt].Next = head[a];
	head[a] = cnt;
}

int dfs(int a, int b) {
	if(dp[a][b]!=FINF) return dp[a][b];
	int i, to;
	if(b==1) {
		dp[a][1] = A[a];
		for(i=head[a];i!=0;i=edge[i].Next) {
			to = edge[i].to;
			dfs(to, 0);
			if(dp[to][0]>0) dp[a][1] += dp[to][0];
		}
	}
	else {
		dp[a][0] = 0;
		for(i=head[a];i!=0;i=edge[i].Next) {
			to = edge[i].to;
			dfs(to, 1);
			dp[a][0] += Max(dp[to][0], dp[to][1]);
		}
	}
	return dp[a][b];
}

int main()
{
	int i, a, b;
	cin>>N;
	for(i=1;i<=N;i++) cin>>A[i];
	for(i=1;i<=N;i++) {
		cin>>a>>b;
		if(a==0) break;
		add(b, a);
	}
	for(i=1;i<=N;i++) {
		dp[i][0] = dp[i][1] = FINF;
	}
	for(i=1;i<=N;i++) {
		dfs(i, 0); ans = Max(ans, dp[i][0]);
		//cout<<i<<"   0  "<<dp[i][0]<<endl;
		dfs(i, 1); ans = Max(ans, dp[i][1]);
		//cout<<i<<"   1  "<<dp[i][1]<<endl;
	}
	cout<<ans<<endl;
	return 0;
}
