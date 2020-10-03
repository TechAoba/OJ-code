#include<iostream>
#include<cstdio>
#include<cstring>
#define Min(a,b) (a<b?a:b)
using namespace std;
const int MAXN = 55;
int dis[MAXN][MAXN], N, M;
bool link[MAXN][MAXN][65];

int main()
{
	memset(dis, 63, sizeof(dis));
	//cout<<dis[1][1]<<endl;
	scanf("%d %d", &N, &M);
	int i, j, k, t, a, b;
	for(i=1;i<=M;i++) {
		scanf("%d %d", &a, &b);
		dis[a][b] = 1;
		link[a][b][0] = true;
	}
	for(k=1;k<65;k++) {
		for(t=1;t<=N;t++) {
			for(i=1;i<=N;i++) {
				for(j=1;j<=N;j++) {
					if(link[i][t][k-1] && link[t][j][k-1]) {
						link[i][j][k] = true;
						dis[i][j] = 1;
					}
				}
			}
		}
	}
	for(t=1;t<=N;t++) {
		for(i=1;i<=N;i++) {
			for(j=1;j<=N;j++) {
				dis[i][j] = Min(dis[i][j], dis[i][t]+dis[t][j]);
			}
		}	
	}
	printf("%d\n", dis[1][N]);
	return 0; 
} 
