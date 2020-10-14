#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Max(a,b) (a>b?a:b)
using namespace std;
int N, dp[105][210], A[105], T;

int main()
{
	scanf("%d", &T);
	for(int kase=0;kase<T;kase++) {
		memset(dp, 0, sizeof(dp));
		scanf("%d", &N);
		int i, j, ans=1;
		for(i=0;i<101;i++) {
			for(j=0;j<201;j++) {
				dp[i][j] = 1;
			}
		}
		for(i=1;i<=N;i++) {
			scanf("%d", &A[i]);
		}
		sort(A+1, A+1+N);
		for(i=1;i<=N;i++) {
			for(j=1;j<i;j++) {
				dp[i][(A[i]-A[j]+200)%200] = dp[j][(A[i]-A[j]+200)%200]+1;
				ans = Max(ans, dp[i][(A[i]-A[j]+200)%200]);
				//printf("j = %d   i = %d  dp = %d\n", j, i, dp[i][(A[i]-A[j]+200)%200]);
			}
		}
		printf("case #%d:\n%d\n", kase, ans);
	}
	return 0;
}
