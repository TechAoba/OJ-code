#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
const int MAXN = 2505;
int R, C, A[MAXN][MAXN], num[MAXN][MAXN], dp[MAXN][MAXN], ans=0;
int up[MAXN][MAXN], lef[MAXN][MAXN];

void fan() {  //把整个数组上下翻转180度 
	int r, r1, c, mid=R/2, t;
	for(r=1;r<=mid;r++) {
		r1=R-r+1;
		for(c=1;c<=C;c++) {
			t=A[r][c], A[r][c]=A[r1][c], A[r1][c]=t;
		}
	}
}

int main()
{
	scanf("%d %d", &R, &C);
	int r, c;
	for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			scanf("%d", &A[r][c]);
			if(A[r-1][c]==1) up[r][c]=1;
			else up[r][c] = up[r-1][c]+1;
			if(A[r][c-1]==1) lef[r][c]=1;
			else lef[r][c] = lef[r][c-1]+1;
			if(A[r][c]==0) dp[r][c]=0;
			else {
				dp[r][c] = Min(dp[r-1][c-1]+1, Min(up[r][c], lef[r][c]));
				ans = Max(ans, dp[r][c]);
			}
		}
	}
	fan();
	for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			if(A[r-1][c]==1) up[r][c]=1;
			else up[r][c] = up[r-1][c]+1;
			if(A[r][c-1]==1) lef[r][c]=1;
			else lef[r][c] = lef[r][c-1]+1;
			if(A[r][c]==0) dp[r][c]=0;
			else {
				dp[r][c] = Min(dp[r-1][c-1]+1, Min(up[r][c], lef[r][c]));
				ans = Max(ans, dp[r][c]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
