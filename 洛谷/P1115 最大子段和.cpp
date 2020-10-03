#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;

int main()
{
	int N, dp, ans=-0x3f3f3f3f, t;
	scanf("%d", &N);
	scanf("%d", &dp);  //dp为选择上一个节点的最优
	ans = Max(ans, dp);
	for(int i=2;i<=N;i++) {
		scanf("%d", &t);
		if(dp>0) dp += t;
		else dp = t;
		ans = Max(ans, dp);
	} 
	printf("%d\n", ans);
	return 0;
}
