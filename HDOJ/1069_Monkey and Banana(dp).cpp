#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define Max(a,b) (a>b?a:b) 
using namespace std;
const int MAXN = 105;
int N, cnt, dp[MAXN];
struct Node{
	int a, b, h;
	bool operator<(const Node &t)const{
		return a==t.a?b<t.b:a<t.a;
	}
}node[MAXN];

int main()
{
	int kase = 0;
	while(scanf("%d", &N) == 1 && N) {
		int i, j, a, b, c;
		cnt = 0;
		for(i=0;i<N;i++) {
			scanf("%d %d %d", &a, &b, &c);
			node[cnt].a = a, node[cnt].b = b, node[cnt++].h = c;
			node[cnt].a = b, node[cnt].b = a, node[cnt++].h = c;
			node[cnt].a = c, node[cnt].b = b, node[cnt++].h = a;
			node[cnt].a = b, node[cnt].b = c, node[cnt++].h = a;
			node[cnt].a = a, node[cnt].b = c, node[cnt++].h = b;
			node[cnt].a = c, node[cnt].b = a, node[cnt++].h = b;
		}
		sort(node, node+cnt);
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		for(i=0;i<cnt;i++) {
			dp[i] = node[i].h;
			for(j=0;j<i;j++) {
				if(node[j].a<node[i].a&&node[j].b<node[i].b)
					dp[i] = Max(dp[i], dp[j]+node[i].h);
			}
			ans = Max(ans, dp[i]);
		}
		printf("Case %d: maximum height = %d\n", ++kase, ans);
	}
	return 0;
}
