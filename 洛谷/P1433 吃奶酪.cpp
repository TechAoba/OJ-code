#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#define Min(a,b) (a<b?a:b)
using namespace std;
int N;
double dist[20][20], dp[20][1<<16];
struct Node{
	double x, y;
	Node(int x=0,int y=0):x(x),y(y){ }
}nodes[20];

double cal(int a, int b) {
	return sqrt((nodes[a].x-nodes[b].x)*(nodes[a].x-nodes[b].x)+(nodes[a].y-nodes[b].y)*(nodes[a].y-nodes[b].y));
}

int main()
{
	memset(dp, 127, sizeof(dp));
	int i, j, k;
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>nodes[i].x>>nodes[i].y;
		for(j=0;j<i;j++) {
			dist[i][j] = dist[j][i] = cal(i, j);
		}
	}
	for(j=1;j<(1<<N);j++) {  //j代表集合 
		for(i=1;i<=N;i++) {  //i表示起始点 
			if(!(j&(1<<(i-1)))) continue;  //起始点不在集合中 
			if(j==(1<<(i-1))) {
				dp[i][j]=0;continue;
			}
			for(k=1;k<=N;k++) {  //k作为下一个起始点 
				if(!(j&(1<<(k-1))) || i==k) continue;
				dp[i][j] = Min(dp[i][j], dp[k][j-(1<<(i-1))] + dist[i][k]);
				//printf("    %.2lf\n", dp[i][j]);
			}
		}
	}
	double ans = 100000000;
	for(i=1;i<=N;i++) {
		//printf("%.2lf\n", dp[i][(1<<N)-1]);
		ans = Min(ans, dist[0][i] + dp[i][(1<<N)-1]);
	}
	printf("%.2lf", ans);
	return 0;
}
