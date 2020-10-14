#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
const int MAXN = 1e5+10, INF = 0x3f3f3f3f;
int A[MAXN], dp[MAXN], N;

int main()
{
	scanf("%d", &N);
	int i;
	for(i=1;i<=N;i++) scanf("%d", &A[i]), dp[i] = INF;
	dp[1] = 0;
	dp[2] = abs(A[1]-A[2]);
	for(i=3;i<=N;i++) {
		dp[i] = Min(dp[i], Min(dp[i-1]+abs(A[i]-A[i-1]), dp[i-2]+abs(A[i]-A[i-2])));
	}
	printf("%d\n", dp[N]);
	return 0;
}
