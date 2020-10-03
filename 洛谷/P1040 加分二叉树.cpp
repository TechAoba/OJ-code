#include<iostream>
#include<cstdio>
using namespace std;
int root[35][35], N, dp[35][35], poi[35];

void show(int left, int right) {
	if(left>right) return;
	if(!(left^right)) {
		printf("%d ", left);
	}
	else {
		int R = root[left][right];
		printf("%d ", R);
		show(left, R-1);
		show(R+1, right);
	}
}

int main()
{
	cin>>N;
	int i, j, k;
	for(i=1;i<=N;i++) cin>>poi[i];
	/*for(i=1;i<=N;i++) {
		for(j=i;j<=N;j++) {
			dp[j][i] = 1;  //大的到小的（空子树）为1 
			if(i==j) dp[i][j] = poi[i];
		}
	}*/
	for(i=1;i<=N;i++) {
		dp[i][i]=poi[i];
		dp[i][i-1] = 1;
	}
	for(i=N;i>=1;i--) {
		for(j=i+1;j<=N;j++) {
			for(k=i;k<=j;k++) {  //把k当作目前的根 
				int tmp = dp[i][k-1]*dp[k+1][j]+poi[k];
				if(tmp>dp[i][j]) {
					root[i][j] = k;
					dp[i][j] = tmp;
				}
			}
		}
	}
	printf("%d\n", dp[1][N]);
	show(1, N);
	return 0;
}
