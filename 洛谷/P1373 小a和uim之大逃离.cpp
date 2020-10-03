#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
const int MOD = 1000000007, MAXN = 801;
int dp[MAXN][MAXN][2][16], R, C, k;
inline int read() {
	int x=0, f=1;
	char c = getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	int r, c, i, nr, nc, T;
	LL ans = 0;
	R=read(),C=read(),k=read();
	for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			T = read();
			dp[r][c][1][T%(k+1)] = 1;
			/* 上面的方块 */
			nr = r-1, nc = c;
			if(nr>=1) {
				for(i=0;i<=k;i++) {
					dp[r][c][0][i] = (dp[r][c][0][i]%MOD + dp[nr][nc][1][(i+T)%(k+1)]%MOD) % MOD;  //奇数 
					dp[r][c][1][i] = (dp[r][c][1][i]%MOD + dp[nr][nc][0][(i-T+k+1)%(k+1)]%MOD) % MOD;
				}
			}
			/* 左边的方块 */
			nr = r, nc = c-1;
			if(nc>=1) {
				for(i=0;i<=k;i++) {
					dp[r][c][0][i] = (dp[r][c][0][i]%MOD + dp[nr][nc][1][(i+T)%(k+1)]%MOD) % MOD;  //奇数 
					dp[r][c][1][i] = (dp[r][c][1][i]%MOD + dp[nr][nc][0][(i-T+k+1)%(k+1)]%MOD) % MOD;
				}
			}
			ans = (ans+dp[r][c][0][0]%MOD)%MOD;
		}
	}
	/*for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			for(i=0;i<=k;i++) {
				printf("r=%lld   c=%lld   k=%lld   奇数步-》%lld   偶数步-》%lld\n", r, c, i, dp[r][c][1][i], dp[r][c][0][i]);
			}
		}
	}*/ 
	printf("%lld\n", ans%MOD);
	return 0;
 } 
