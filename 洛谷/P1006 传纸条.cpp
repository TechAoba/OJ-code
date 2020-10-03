#include<iostream>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
int A[55][55], dp[105][55][55];

int main()
{
	memset(dp,-1,sizeof(dp));
	int R, r, C, c, i, j, k;
	cin>>R>>C;
	for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			cin>>A[r][c];
		}
	} 
	dp[2][1][1]=0;
	for(k=3;k<R+C;k++) {
		for(i=1;i<R;i++) {
			for(j=i+1;j<=R;j++) {
				dp[k][i][j] = Max(dp[k][i][j], dp[k-1][i][j]);
				dp[k][i][j] = Max(dp[k][i][j], dp[k-1][i-1][j]);
				dp[k][i][j] = Max(dp[k][i][j], dp[k-1][i][j-1]);
				dp[k][i][j] = Max(dp[k][i][j], dp[k-1][i-1][j-1]);
				if(dp[k][i][j]==-1) continue;
				dp[k][i][j] += A[i][k-i] + A[j][k-j];
			}
		}
	}
	cout<<dp[R+C-1][R-1][R]<<endl;
	return 0;
}
