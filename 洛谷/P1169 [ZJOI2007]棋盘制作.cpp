#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define res register int
using namespace std;

const int MAXN = 2005, INF = 0x3f3f3f3f;
int A[MAXN][MAXN], R, C, dp[MAXN][MAXN], L[MAXN][MAXN], U[MAXN][MAXN], ans=-INF, ans1=0;

inline int read() {
	int x=0,f=1;
	char c = getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	R = read(), C = read();
	res r, c, i;
	for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			A[r][c] = read();
			if(r==1 || c==1 || A[r-1][c]!=1-A[r][c] || A[r][c-1]!=1-A[r][c] || A[r-1][c-1]!=A[r][c]) dp[r][c] = 1;
			else {
				dp[r][c] = Min(dp[r-1][c], Min(dp[r-1][c-1], dp[r][c-1]))+1;
			}
			ans = Max(ans, dp[r][c]);
			if(c==1||A[r][c]==A[r][c-1]) L[r][c]=1;
			else L[r][c] = L[r][c-1]+1;
			if(r==1||A[r][c]==A[r-1][c]) U[r][c] = 1;
			else U[r][c] = U[r-1][c]+1;
			int width=L[r][c], ww = r-U[r][c]+1;
			for(i=r;i>=ww;i--) {
				width = Min(width, L[i][c]);
				ans1 = Max(ans1, width*(r-i+1));
			}
		}
	}
	printf("%d\n%d\n", ans*ans, ans1);
	return 0;
}
