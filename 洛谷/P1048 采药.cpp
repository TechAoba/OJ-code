#include<iostream>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 1005;
int M, N, A[105], V[105], dp[MAXN];

int main()
{
	memset(dp, 0, sizeof(dp));
	int i, j;
	cin>>M>>N;
	for(i=1;i<=N;i++) cin>>V[i]>>A[i];
	for(i=1;i<=N;i++) {
		for(j=M;j>=V[i];j--) dp[j] = Max(dp[j], dp[j-V[i]]+A[i]);
	}
	cout<<dp[M]<<endl;
	return 0;
}
