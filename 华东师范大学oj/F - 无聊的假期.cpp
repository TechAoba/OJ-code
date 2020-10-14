#include<iostream>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 1e5+10;
int dp[MAXN][4], A[MAXN], B[MAXN], C[MAXN], N;

int read() {
	int num=0;
	char c=getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') num=(num<<3)+(num<<1)+(c^48),c=getchar();
	return num;
}

int main()
{
	N=read();
	int i, ans;
	for(i=1;i<=N;i++) {
		A[i]=read(), B[i]=read(), C[i]=read();
	}
	dp[1][1]=A[1], dp[1][2]=B[1], dp[1][3]=C[1];
	for(i=2;i<=N;i++) {
		dp[i][1] = Max(dp[i-1][2], dp[i-1][3])+A[i];
		dp[i][2] = Max(dp[i-1][1], dp[i-1][3])+B[i];
		dp[i][3] = Max(dp[i-1][1], dp[i-1][2])+C[i];
	}
	ans=Max(dp[N][1], Max(dp[N][2], dp[N][3]));
	cout<<ans;
	return 0;
}
