#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define Min(a,b) (a<b?a:b)
using namespace std;
const int INF = 0x3f3f3f3f;
int N, M, cnt = 0, dis[55][55], dp[11][1<<11];
struct Node{
	int r, c;
}node[15];

int main()
{
	while(scanf("%d %d", &N, &M) != EOF) {
		int i, j, a, S;
		node[0].r = node[0].c = 0;
		cnt = 1;
		for(i=0;i<N;i++) {
			for(j=0;j<M;j++) {
				scanf("%d", &a);
				if(i==0&&j==0) continue;
				if(a!=0) {
					node[cnt].r = i;
					node[cnt].c = j;
					cnt++;
				}
			}
		}
		//cout<<"   "<<cnt<<endl;
		memset(dis, INF, sizeof(dis));
		for(i=0;i<cnt;i++) {
			for(j=0;j<=i;j++) {
				dis[i][j] = dis[j][i] = abs(node[i].r-node[j].r)+abs(node[i].c-node[j].c);
				//printf("%d %d距离是%d\n", i, j, dis[i][j]);
			}
		}
		
		memset(dp, INF, sizeof(dp));
		dp[0][0] = 0;
		for(S=0;S<(1<<cnt);S++) {  //经过的集合 
			for(i=0;i<cnt;i++) {
				for(j=0;j<cnt;j++) {
					dp[j][S^(1<<i)] = Min(dp[j][S^(1<<i)], dp[i][S] + dis[i][j]);
				} 
			}
		}
		printf("%d\n", dp[0][(1<<cnt)-1]);
	}
	return 0;
}
