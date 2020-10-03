#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 105, INF = 0x3f3f3f3f;
int A[MAXN][MAXN], N, ans;

int main()
{
	while(scanf("%d", &N) != EOF) {
		if(N<1) break;
		ans = -INF;
		int i, j, t, k;
		for(i=1;i<=N;i++) {
			for(j=1;j<=N;j++) {
				scanf("%d", &t);
				A[i][j] = A[i-1][j] + t;
			}
		}
		for(i=1;i<=N;i++) {
			for(j=0;j<i;j++) {
				int temp = -INF;
				for(k=1;k<=N;k++) {
					temp = Max(temp, 0) + A[i][k] - A[j][k];
					ans = Max(ans, temp);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
