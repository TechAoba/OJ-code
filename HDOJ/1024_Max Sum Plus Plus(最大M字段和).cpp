#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 1e6+10, INF = 0x3f3f3f3f;
int N, M, A[MAXN], dp[MAXN], pre[MAXN];

int main()
{
	int i, j;
	while(scanf("%d %d", &M, &N) != EOF) {
		for(i=1;i<=N;i++) scanf("%d", &A[i]);
		int ans;
		memset(dp, 0, sizeof(dp));
		memset(pre, 0, sizeof(pre));
		for(i=1;i<=M;i++) { //·ÖÎªi¶Î 
			ans = -INF;
			for(j=i;j<=N;j++) {
				dp[j] = Max(dp[j-1], pre[j-1]) + A[j];
				pre[j-1] = ans;
				ans = Max(ans, dp[j]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
