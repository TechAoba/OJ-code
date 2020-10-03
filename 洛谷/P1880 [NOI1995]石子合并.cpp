#include<iostream>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
int A[205], sum[205], N, DP[205][205], dp[205][205]; 

int main()
{
	cin>>N;
	int i, j;
	for(i=1;i<=N;i++) {
		cin>>A[i];
		A[i+N] = A[i];
	}
	for(i=1;i<=2*N;i++) {
		sum[i] = sum[i-1] + A[i];
	}
	for(int len=2;len<=N;len++) {
		for(i=1;i+len-1<=2*N;i++) {
			int en = i+len-1;
			int Tmax = -0x3f3f3f3f;
			int Tmin = 0x3f3f3f3f;
			for(j=i;j<en;j++) {
				Tmax = Max(Tmax, DP[i][j]+DP[j+1][en]+sum[en]-sum[i-1]);
				Tmin = Min(Tmin, dp[i][j]+dp[j+1][en]+sum[en]-sum[i-1]);
			}
			DP[i][en] = Tmax;
			dp[i][en] = Tmin;
		}
	}
	int Tmax = -0x3f3f3f3f;
	int Tmin = 0x3f3f3f3f;
	for(i=1;i<=N;i++) {
		Tmax = Max(Tmax, DP[i][i+N-1]);
		Tmin = Min(Tmin, dp[i][i+N-1]);
	}
	cout<<Tmin<<endl<<Tmax<<endl;
	return 0;
}
