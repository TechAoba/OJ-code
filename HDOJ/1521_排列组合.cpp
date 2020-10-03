#include<iostream>
#include<cstdio>
using namespace std;
int C[11][11], num[11], A[11], N, M, ans=0;

void dfs(int poi, int left) {
	int i;
	if(left==0) return;
	if(poi==M && left>0) {
		num[M] = left;
		int add=1, sheng=N;
		for(i=1;i<=M;i++) {
			add *= C[sheng][num[i]];
			sheng -= num[i];
		}
		ans += add;
		return;
	}
	for(i=left-1;i>0;i--) {
		num[poi] = i;
		dfs(poi+1, left-i);
	}
}

int main()
{
	int i, j;
	for(i=0;i<11;i++) {
		for(j=0;j<=i;j++) {
			if(j==0 || i==j) C[i][j] = 1;
			else C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	scanf("%d %d", &N, &M);
	for(i=1;i<=N;i++) scanf("%d", &A[i]);
	dfs(1, M);
	printf("%d\n", ans);
	return 0;
 } 
