#include<iostream>
#include<cstdio>
#include<cstring>
#define Min(a,b) (a<b?a:b)
using namespace std;
const int MAXN = 2005;
int dp[MAXN][MAXN], C[MAXN][MAXN], T, K;
inline int read() {
	int x=0,f=1;
	char c = getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	T = read(), K=read();
	int i, j;
	C[0][0] = C[1][0] = C[1][1] = 1;
	for(i=2;i<=2000;i++) {
		C[i][0] = 1;
		for(j=1;j<=i;j++) {
			C[i][j] = (C[i-1][j]+C[i-1][j-1]) % K;
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];  //不必考虑K=1的情况  因为没这个数据 
			if(!C[i][j]) dp[i][j]++;
		}
		dp[i][i+1] = dp[i][i];
	}
	while(T--) {
		int N = read(), M = read();
		printf("%d\n", dp[N][Min(N, M)]);
	}
	return 0;
}
