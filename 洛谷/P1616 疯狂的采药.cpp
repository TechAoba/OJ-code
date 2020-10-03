#include<iostream>
#include<cstring>
#include<cstdio>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 100010;
int T, dp[MAXN], A[10005], V[10005];

int main()
{
	memset(dp,0,sizeof(dp));
	int N, i, j;
	scanf("%d %d", &T, &N);
	for(i=1;i<=N;i++) scanf("%d %d", &V[i], &A[i]);
	for(i=1;i<=N;i++) {
		for(j=V[i];j<=T;j++) {
			dp[j] = Max(dp[j], dp[j-V[i]]+A[i]);
		}
	}
	cout<<dp[T]<<endl;
	return 0;
}
