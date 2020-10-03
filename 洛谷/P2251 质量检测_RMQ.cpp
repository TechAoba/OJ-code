#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define res register int
#define Min(a,b) (a<b?a:b)
using namespace std;
const int MAXN = 100005;
int dp[MAXN][18], N, M;

inline int read() {
	int x=0, f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

inline int ans(int l, int r) {
	int k = log2(r-l+1);
	return Min(dp[l][k], dp[r+1-(1<<k)][k]);
}

int main()
{
	N=read(), M=read();
	res i, j;
	for(i=1;i<=N;i++) dp[i][0] = read();
	for(j=1;j<18;j++) {
		for(i=1;i+(1<<j)-1<=N;i++) {
			dp[i][j] = Min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
		}
	}
	for(i=M;i<=N;i++) {
		printf("%d\n", ans(i-M+1, i));
	}
	return 0;
}
