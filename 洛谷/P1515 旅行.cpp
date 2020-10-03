#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int dp[7005], A, B, N, dis[7005], cnt=0;
bool vis[7005];

int main()
{
	dp[0] = 1;
	vis[0] = vis[990] = vis[1010] = vis[1970] = vis[2030] = vis[2940] = vis[3060] = 1;
	vis[3930] = vis[4060] = vis[4970] = vis[5030] = vis[5990] = vis[6010] = vis[7000] = 1;
	int i, j, a;
	scanf("%d %d %d", &A, &B, &N);
	for(i=0;i<N;i++) {
		scanf("%d", &a);
		vis[a] = 1;
	}
	for(i=0;i<7001;i++) {
		if(vis[i]) {
			dis[cnt++] = i;
		}
	}
	for(i=1;i<cnt;i++) {
		for(j=i-1;j>=0;j--) {
			int u = dis[i];
			int v = dis[j];
			if(u-v>=A && u-v<=B) dp[u] += dp[v];
		}
	}
	printf("%d\n", dp[7000]);
	return 0;
 } 
