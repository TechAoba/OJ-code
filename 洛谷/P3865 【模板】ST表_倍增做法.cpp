#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define res register int
using namespace std;
const int MAXN = 100005;
int dp[MAXN][18], N, M;  //´Ó17¿ªÊ¼

inline int read() {
	int x=0, f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	N=read(), M=read();
	res i, j, a, b;
	for(i=1;i<=N;i++) dp[i][0] = read();
	for(j=1;(1<<j)<=N;j++) {
		for(i=1;i<=N;i++) {
			if(i+(1<<j)-1<=N) {
				dp[i][j] = Max(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
			}
		}
	}
	for(i=1;i<=M;i++) {
		a = read(), b=read();
		int ans = -0x3f3f3f3f;
		for(j=17;j>=0;j--) {
			if(a+(1<<j)-1<=b) {
				ans = Max(ans, dp[a][j]);
				a += (1<<j);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
 } 
