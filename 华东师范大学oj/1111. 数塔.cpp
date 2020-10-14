#include<iostream>
#include<cstdio>
#include<cstring>
#define Min(a,b) (a<b?a:b)
using namespace std;
int M, N, dp[105][105], ans;
const int INF = 0x3f3f3f3f;

int main()
{
	cin>>M;
	int i, j;
	while(M--) {
		cin>>N;
		ans = INF;
		for(i=1;i<=N;i++) {
			for(j=1;j<=i;j++) {
				cin>>dp[i][j];
				if(j==1) dp[i][j] += dp[i-1][j];
				else if(i==j) dp[i][j] += dp[i-1][j-1];
				else dp[i][j] += Min(dp[i-1][j], dp[i-1][j-1]);
				if(i==N) ans = Min(ans, dp[i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
