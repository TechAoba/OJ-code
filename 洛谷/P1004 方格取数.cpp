#include<iostream>
#include<cstring>
#include<cstdio>
#define Max(a,b) (a>b?a:b)
using namespace std;
int A[10][10], N, dp[25][25][25];

int main()
{
	memset(dp, -1, sizeof(dp));
	cin>>N;
	int r, c, k, i, j, num;
	while(scanf("%d %d %d", &r, &c, &num) == 3 && r!=0) {
		A[r][c] = num;
	}
	dp[2][1][1] = A[1][1];
	for(k=3;k<=N*2;k++) {
		for(i=1;i<k;i++) {
			for(j=1;j<k;j++) {
				dp[k][i][j] = Max(dp[k][i][j], dp[k-1][i][j]);
				dp[k][i][j] = Max(dp[k][i][j], dp[k-1][i-1][j]);
				dp[k][i][j] = Max(dp[k][i][j], dp[k-1][i][j-1]);
				dp[k][i][j] = Max(dp[k][i][j], dp[k-1][i-1][j-1]);
				if(dp[k][i][j]==-1) continue;
				dp[k][i][j] += A[i][k-i] + A[j][k-j];
				if(i==j) dp[k][i][j] -= A[i][k-i];
			}
		}
	}
	cout<<dp[2*N][N][N]<<endl;
	return 0;
}
