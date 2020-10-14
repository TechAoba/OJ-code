#include<iostream>
#include<cstdio>
#include<cstring>
#define res register int
#define LL long long
using namespace std;
const int MOD = 100000007;
int T, N, K, kase, A[105], use[100005];
LL dp[100005];

int main()
{
	scanf("%d", &T);
	res i, j;
	for(kase=1;kase<=T;kase++) {
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		scanf("%d %d", &N, &K);
		for(i=1;i<=N;i++) scanf("%d", &A[i]);
		for(res i=1;i<=N;i++) {
			memset(use, 0, sizeof(use));
			for(j=A[i];j<=K;j++) {
				if(use[j-A[i]] < K) {
					use[j] = use[j-A[i]]+1;
					dp[j] = (dp[j] + dp[j-A[i]])%MOD;
				}
			}
		}
		printf("Case %d: %lld\n", kase, dp[K]);
	}
	return 0;
}
