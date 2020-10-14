#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
int dp[1005][16][16];

struct Node{
	int a, b, t;
	bool operator <(const Node &z)const{
		return t>z.t;
	}
}node[1005];

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	int ans=0, a, b, cnt=0, i, j, k;
	while(scanf("%d %d", &a, &b)!=EOF) {
		node[++cnt].a=a; node[cnt].b=b;
		node[cnt].t = Max(a, b);
	}
	for(i=1;i<=cnt;i++) {
		for(j=0;j<=15;j++) {
			for(k=0;k<=15;k++) {
				if(j==0&&k==0) continue;
				else if(j==0) dp[i][j][k] = Max(dp[i-1][j][k], dp[i-1][j][k-1]+node[i].b);
				else if(k==0) dp[i][j][k] = Max(dp[i-1][j][k], dp[i-1][j-1][k]+node[i].a);
				else dp[i][j][k] = Max(dp[i-1][j][k], Max(dp[i-1][j][k-1]+node[i].b, dp[i-1][j-1][k]+node[i].a));
			}
		}
	}
	printf("%d\n", dp[cnt][15][15]);
	return 0;
} 
