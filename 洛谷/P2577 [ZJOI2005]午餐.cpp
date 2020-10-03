#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
using namespace std;
int sum[205], N, ans=0x3f3f3f3f, dp[205][205*205];
struct Node{
	int a, b;
	bool operator <(const Node &t)const {
		return b>t.b;
	}
}node[205];

int main()
{
	int i, j, k;
	scanf("%d", &N);
	for(i=1;i<=N;i++) {
		scanf("%d %d", &node[i].a, &node[i].b);
	}
	sort(node+1, node+1+N);
	for(i=1;i<=N;i++) sum[i] = sum[i-1] + node[i].a;
	memset(dp, 127, sizeof(dp));
	dp[0][0] = 0;
	for(i=1;i<=N;i++) {
		for(j=sum[i];j>=0;j--) {
			if(j>=node[i].a) dp[i][j] = Min(dp[i][j], Max(dp[i-1][j-node[i].a], j+node[i].b));
			dp[i][j] = Min(dp[i][j], Max(dp[i-1][j], sum[i]-j+node[i].b));
		}
	}
	for(j=0;j<=sum[N];j++) ans = Min(ans, dp[N][j]);
	printf("%d\n", ans);
	return 0;
} 
