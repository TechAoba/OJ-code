#include<iostream>
#include<stack>
#define LL long long
using namespace std;
LL dp[20];

int main() 
{
	int N, i, j;
	cin>>N;
	dp[0] = dp[1] = 1;
	for(i=2;i<=N;i++) {
		for(j=0;j<i;j++) {
			dp[i] += dp[j] * dp[i-1-j];
		}
	}
	cout<<dp[N]<<endl;
	return 0; 
} 
