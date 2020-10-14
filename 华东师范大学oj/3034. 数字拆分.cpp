#include<iostream>
#include<cstdio>
#define res register int
#define LL long long
using namespace std;
const int MAXN = 1000005;
LL dp[MAXN];
int T, a;

int main()
{
	dp[1] = 1;
	res i;
	for(i=2;i<=1000000;i++) {
		if(i&1) dp[i] = dp[i-1];
		else dp[i] = (dp[i-1]+dp[i/2])%1000000000;
	}
	scanf("%d", &T);
	for(int kase = 0;kase<T;kase++) {
		scanf("%d", &a);
		printf("case #%d:\n%lld\n", kase, dp[a]);
	}
	return 0;
}
