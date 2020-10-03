#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e6+10;
int ans, N, M, A[MAXN], dp[MAXN];

int main()
{
	int i;
	while(scanf("%d %d", &M, &N) != EOF) {
		for(i=1;i<=N;i++) {
			scanf("%d", &A[i]);
			dp[i] = A[i];
			if(dp[i-1]>0) dp[i] += dp[i-1];
		}
		sort(dp+1, dp+1+N, greater<int>());
		ans = 0;
		for(i=1;i<=M;i++) ans += dp[i];
		printf("%d\n", ans);
	}
	return 0;
}
