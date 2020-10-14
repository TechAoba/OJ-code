#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n, p, m, t, M, dp[105][105];

int main()
{
	scanf("%d", &M);
	int i, j;
	while(M--) {
		cin>>n>>p>>m>>t;
		memset(dp, 0, sizeof(dp));
		dp[0][p] = 1;
		for(i=1;i<=m;i++) {
			for(j=1;j<=n;j++) {
				dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
			}
		}
		cout<<dp[m][t]<<endl;
	}
	return 0;
}
