#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define LL long long
using namespace std;
LL dp[100005], N, M, A, B, C;

int main()
{
	scanf("%lld %lld", &N, &M);
	LL i, ans=0, last, now, tmin, tmax;
	scanf("%lld", &last);
	for(i=2;i<=M;i++) {
		scanf("%lld", &now);
		if(now>last) {
			dp[last]++;
			dp[now]--;
		}
		else {
			dp[last]--;
			dp[now]++;
		}
		last = now;
	}
	for(i=1;i<N;i++) {
		dp[i] += dp[i-1];
		scanf("%lld %lld %lld", &A, &B, &C);
		/*printf("对于%d号线路: 走%lld遍,", i, dp[i]);
		if(A*dp[i] > C+B*dp[i]) {
			printf("选择买卡，花费%lld元\n", C+B*dp[i]);
		}
		else {
			printf("选择买票，花费%lld元\n", A*dp[i]);
		}*/
		ans += Min(A*dp[i], C+B*dp[i]);
	}
	printf("%lld\n", ans);
	return 0;
} 
