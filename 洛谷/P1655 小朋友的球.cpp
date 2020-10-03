#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 1005, MOD = 1e9+7;
LL N, M, dp[MAXN];

int main()
{
	while(scanf("%lld %lld", &N, &M) != EOF) {
		int i, j;
		if(M>N) {
			printf("0\n");
			continue;
		}
		if(M==N || M==1) {
			printf("1\n");
			continue;
		}
		dp[1] = dp[2] = 1;
		for(i=3;i<=N;i++) {
			for(j=Min(i, M);j>1;j--) {
				if(i==j) {
					dp[j] = 1;
					continue;
				}
				dp[j] = (dp[j-1] + dp[j]*j) % MOD;
			}
		}
		printf("%lld\n", dp[M]);
	}
	return 0;
}
