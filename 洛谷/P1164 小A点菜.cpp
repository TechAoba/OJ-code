#include<iostream>
#define Max(a,b) (a>b?a:b)
using namespace std;
int dp[10005], A[105];

int main()
{
	int N, M, i, j;
	cin>>N>>M;
	for(i=1;i<=N;i++) {
		cin>>A[i];
	}
	for(i=1;i<=N;i++) {
		for(j=M;j>=A[i];j--) {
			dp[j] += dp[j-A[i]];
			if(j==A[i]) dp[j]++;
		}
	}
	cout<<dp[M];
	return 0;
}
