#include<iostream>
#define Max(a,b) (a>b?a:b)
using namespace std;
int dp[1005][1005], N; 

int main()
{
	cin>>N;
	int i, j;
	for(i=1;i<=N;i++) {
		for(j=1;j<=i;j++) {
			cin>>dp[i][j];
		}
	}
	for(i=N-1;i>=1;i--) {
		for(j=1;j<=i;j++) {
			dp[i][j] += Max(dp[i+1][j], dp[i+1][j+1]);
		}
	}
	cout<<dp[1][1];
	return 0;
}
