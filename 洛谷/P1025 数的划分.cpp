#include<iostream>
using namespace std;
int dp[205][10];  //i个小球分成j份的方案数 

int main()
{
	int K, N, i, j;
	cin>>K>>N;
	for(j=1;j<=N;j++) {  //j个抽屉放i个球 
		for(i=j;i<=K;i++) {
			if(j==1) dp[i][j] = 1;
			else {
				dp[i][j] = dp[i-1][j-1] + dp[i-j][j];
				//cout<<i<<"  "<<j<<"  "<<dp[i][j]<<endl;
			} 
		}
	}
	cout<<dp[K][N];
	return 0;
}
