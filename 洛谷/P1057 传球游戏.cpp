#include<iostream>
#define LL long long
using namespace std;
int N, M;  //N个人  M次 
LL dp[35][35];

int main()
{
	dp[0][0] = 1;  //初始 
	cin>>N>>M;
	for(int i=1;i<=M;i++) {
		for(int j=0;j<N;j++) {
			if(j==0) dp[i][j] = dp[i-1][N-1] + dp[i-1][1];
			else if(j==N-1) dp[i][j] = dp[i-1][N-2] + dp[i-1][0];
			else dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
		}
	}
	cout<<dp[M][0];
	return 0;
}
