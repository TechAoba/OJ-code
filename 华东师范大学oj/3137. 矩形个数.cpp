#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int R, C, N, K, T, A[15][15], dp[15][15];

int main()
{
	scanf("%d", &T);
	for(int kase=0;kase<T;kase++) {
		memset(A, 0, sizeof(A));
		memset(dp, 0, sizeof(dp));
		scanf("%d %d %d %d", &R, &C, &N, &K);
		int r, c, r1, c1, i, ans=0;
		for(i=0;i<N;i++) {
			scanf("%d %d", &r, &c);
			A[r][c] = 1;
		}
		for(r=1;r<=R;r++) {
			for(c=1;c<=C;c++) {
				dp[r][c] = dp[r-1][c]+dp[r][c-1]-dp[r-1][c-1];
				if(A[r][c]) dp[r][c] += 1;
				for(r1=1;r1<=r;r1++) {
					for(c1=1;c1<=c;c1++) {
						int t = dp[r][c] - dp[r][c1-1] - dp[r1-1][c] + dp[r1-1][c1-1];
						if(t>=K) ans++;
					}
				}
			}
		}
		printf("case #%d:\n%d\n", kase, ans);
	}
	
	return 0;
 } 
