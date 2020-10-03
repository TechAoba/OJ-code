#include<iostream>
using namespace std;
const int maxn = 100000+10, mod = 100003;
int dp[maxn] = {0};

int main()
{
	int N, K, i, j;
	dp[0] = 1;
	cin>>N>>K;
	for(i=1;i<=N;i++) {
		int T = 0;
		for(j=1;j<=K;j++) {
			int tmp = i-j;
			if(tmp>=0) T = (T+dp[tmp])%mod;
		}
		dp[i] = T%mod;
	}
	cout<<dp[N];
	return 0;
}
