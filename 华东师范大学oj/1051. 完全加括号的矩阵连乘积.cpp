#include<iostream>
#include<cstdio>
#define Min(a,b) (a<b?a:b)
#define LL long long
#define res register int 
using namespace std;
int T, N, L[55], R[55];
LL dp[55][55];
const LL INF = 4611686018427387904;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	T = read();
	while(T--) {
		N = read();
		res i, l, j, m;
		for(i=1;i<=N;i++) L[i]=read(), R[i]=read();
		for(i=1;i<N;i++) dp[i][i+1] = (LL)L[i]*R[i]*R[i+1];
		for(l=3;l<=N;l++) {
			for(i=1;i<=N-l+1;i++) {
				j = i+l-1;
				dp[i][j] = INF;
				for(m=i;m<j;m++) {
					dp[i][j] = Min(dp[i][j], dp[i][m]+dp[m+1][j]+L[i]*R[m]*R[j]);
				}
			}
		}
		cout<<dp[1][N]<<endl;
	}
	return 0;
}
