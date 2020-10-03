#include<iostream>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
int C[5], A[355], dp[45][45][45][45];

int get(int a, int b, int c, int d) {
	int num = a+b*2+c*3+d*4;
	return A[num+1];
}

int main()
{
	memset(C, 0, sizeof(C));
	memset(dp, 0, sizeof(dp));
	int i, j, k, m, N, M, t;
	cin>>N>>M;
	for(i=1;i<=N;i++) cin>>A[i];
	dp[0][0][0][0] = A[1];
	for(i=0;i<M;i++) {
		cin>>j;
		C[j]++;
	}
	for(i=0;i<=C[1];i++) {
		for(j=0;j<=C[2];j++) {
			for(k=0;k<=C[3];k++) {
				for(m=0;m<=C[4];m++) {
					t=0;
					if(i-1>=0) t = Max(t, dp[i-1][j][k][m]);
					if(j-1>=0) t = Max(t, dp[i][j-1][k][m]);
					if(k-1>=0) t = Max(t, dp[i][j][k-1][m]);
					if(m-1>=0) t = Max(t, dp[i][j][k][m-1]);
					dp[i][j][k][m] = t+get(i, j, k, m);
					//cout<<"   i="<<i<<"   j="<<j<<"   k="<<k<<"   m="<<m<<"   "<<dp[i][j][k][m]<<endl;
				}
			}
		} 
	} 
	cout<<dp[C[1]][C[2]][C[3]][C[4]];
	return 0;
}
