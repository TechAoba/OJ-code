#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define Max(a,b) (a>b?a:b)
using namespace std;
const LL MAXN = 105, MOD = 9999973;
LL dp[MAXN][MAXN][MAXN];
LL N, M;

inline LL C(int a) {
	return (a*(a-1))/2;
}

int main()
{
	LL i,j,k;
	LL ans = 0;
	scanf("%d %d", &N, &M);
	dp[0][0][0] = 1;
	for(i=1;i<=N;i++) {
		for(j=0;j<=M;j++) {
			for(k=0;k<=M-j;k++) {
				LL &t = dp[i][j][k];
				t = dp[i-1][j][k];
				if(j>=2) t = (t + dp[i-1][j-2][k]*C(M-j+2-k))%MOD;
				if(k>=1) t = (t + dp[i-1][j][k-1]*j*(M-j-k+1))%MOD;
				if(k>=2) t = (t + dp[i-1][j+2][k-2]*C(j+2))%MOD;
				if(j>=1) t = (t + dp[i-1][j-1][k]*(M-j-k+1))%MOD;
				if(k>=1) t = (t + dp[i-1][j+1][k-1]*(j+1))%MOD;
			}
		}
	}
	for(j=0;j<=M;j++) {
		for(k=0;k<=M-j;k++) {
			ans = (ans + dp[N][j][k])%MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
 } 
