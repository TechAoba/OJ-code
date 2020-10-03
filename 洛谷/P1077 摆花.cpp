#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;

const int MOD = 1000007;
int dp[105][105], A[105], N, M; 

int main()
{
	cin>>N>>M;
	register int i, j, k;
	for(i=1;i<=N;i++) cin>>A[i];
	dp[0][0] = 1;
	for(i=1;i<=N;i++) {  //以i类花作为结尾  j位置
		for(j=0;j<=M;j++) {
			for(k=0;k<=A[i] && k<=j;k++) {
				dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % MOD;
			}
			//cout<<"i="<<i<<"  j="<<j<<"  "<<dp[i][j]<<endl;
		}
	}
	printf("%d\n", dp[N][M]);
	return 0;
}
