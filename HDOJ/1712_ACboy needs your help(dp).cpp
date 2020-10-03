#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
int A[105][105], dp[105][105], N, M;

int main()
{
	int i, j, k;
	while(scanf("%d %d", &N, &M) != EOF) {
		if(N==0 && M==0) break;
		int ans = 0;
		for(i=1;i<=N;i++) {
			for(j=1;j<=M;j++) {
				scanf("%d", &A[i][j]);
			}
		}
		memset(dp, 0, sizeof(dp));
		for(i=1;i<=N;i++) {
			for(j=1;j<=M;j++) {
				for(k=0;k<=j;k++) {
					dp[i][j] = Max(dp[i][j], dp[i-1][j-k] + A[i][k]);
				}
				ans = Max(ans, dp[i][j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
} 
