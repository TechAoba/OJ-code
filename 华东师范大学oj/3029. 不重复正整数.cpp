#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int T, N, M, dp[55];

int main()
{
	cin>>T;
	for(int kase=0;kase<T;kase++) {
		cin>>N>>M;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int add, i;
		for(add=1;add<=M;add++) {
			for(i=N;i>=add;i--) dp[i] += dp[i-add];
		}
		cout<<"case #"<<kase<<":"<<endl<<dp[N]<<endl;
	}
	return 0;
 } 
