#include<iostream>
#include<cstdio>
#include<cstring>
#define Min(a,b) (a<b?a:b)
using namespace std;
int dp[100001][21], N, M;

int main()
{
	int i, j, st, en;
	scanf("%d %d", &N, &M);
	for(i=1;i<=N;i++) scanf("%d", &dp[i][0]);
	for(j=1;(1<<j)<=N;j++) {
		for(i=1;i<=N;i++) {
			if(i+(1<<j)-1<=N) dp[i][j] = Min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
		}
	}
	bool ok = 0;
	while(M--) {
		scanf("%d %d", &st, &en);
		int ans = 0x3f3f3f3f;
		while(st<=en) {
			for(j=20;j>=0;j--) {  //2µÄj´Î·½ 
				if(st+(1<<j)-1<=en) break;
			}
			ans = Min(ans, dp[st][j]);
			st += (1<<j);
		}
		if(ok) putchar(' ');
		ok = 1;
		printf("%d", ans);
	}
	return 0;
}
