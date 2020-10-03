#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
int N, M, A[105], cha[105], dp[105][105][10], dp1[105][105][10];  //dp1算小的 
const int INF = 0x7fffffff;

inline int fun(int a, int b) {
	return (cha[b]-cha[a-1]+20)%10;
}

int main()
{
	memset(dp, 0, sizeof(dp));
	memset(dp1, 0, sizeof(dp1));
	int i, j, k, l, ansx=INF, ansd=-1;
	cin>>N>>M;
	for(i=1;i<101;i++) {
		for(j=1;j<101;j++) {
			for(k=1;k<10;k++) {
				dp1[i][j][k] = INF;
			}
		}
	} 
	for(i=1;i<=N;i++) {
		scanf("%d", &A[i]);
		A[i+N] = A[i];
	}
	cha[0]=0;
	for(i=1;i<=2*N;i++) {
		cha[i] = ((cha[i-1]+A[i])%10+10)%10;
	}
	for(k=1;k<=M;k++) {
		for(i=1;i<=2*N;i++) {
			for(j=i;j<=2*N && j-i<N;j++) {
				if(k==1) {
					dp[i][j][k] = fun(i, j);  //不分段 
					dp1[i][j][k] = fun(i, j);
				}
				else for(l=i;l<j;l++) {
					if(l-i+1>=k-1) {
						dp[i][j][k] = Max(dp[i][j][k], dp[i][l][k-1]*fun(l+1, j));
						dp1[i][j][k] = Min(dp1[i][j][k], dp1[i][l][k-1]*fun(l+1, j));
					}
					if(j-l>=k-1) {
						dp[i][j][k] = Max(dp[i][j][k], fun(i, l)*dp[l+1][j][k-1]);
						dp1[i][j][k] = Min(dp1[i][j][k], fun(i, l)*dp1[l+1][j][k-1]);
					}
				}
			}
		}
	}
	for(i=1;i<=N;i++) {
		ansd = Max(ansd, dp[i][i+N-1][M]);
		ansx = Min(ansx, dp1[i][i+N-1][M]);
	}
	cout<<ansx<<endl<<ansd<<endl;
	return 0;
 } 
