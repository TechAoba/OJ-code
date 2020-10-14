#include<iostream>
#include<cstdio>
#include<cstring>
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 25, MAXM = 100005;
int W[MAXN], P[MAXN], N, M, dp[MAXM], T;

int main()
{
	cin>>T;
	while(T--) {
		scanf("%d %d", &N, &M);
		memset(dp, 0, sizeof(dp));
		int i, j;
		for(i=1;i<=N;i++) {
			scanf("%d %d", &W[i], &P[i]);
			for(j=M;j>=W[i];j--) dp[j] = Max(dp[j], dp[j-W[i]]+P[i]);
		}
		cout<<dp[M]<<endl;
	}
	return 0;
}
