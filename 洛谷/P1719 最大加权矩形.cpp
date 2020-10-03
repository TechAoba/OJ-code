#include<iostream>
#include<cstdio>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 125;
int dp[MAXN][MAXN], N, ans=0;

int main()
{
	scanf("%d", &N);
	for(int i=1;i<=N;i++) {
		for(int j=1;j<=N;j++) {
			scanf("%d", &dp[i][j]);
			
		}
	}
	return 0;
}
