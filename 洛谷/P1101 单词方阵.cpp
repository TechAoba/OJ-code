#include<iostream>
#include<cstdio>
using namespace std;
char A[105][105];
bool vis[105][105];
int N;
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
char target[10] = "yizhong";

int main()
{
	int i, j, k;
	cin>>N;
	for(i=1;i<=N;i++) {
		scanf("%s", A[i]+1);
	}
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			if(A[i][j]=='y') {
				for(k=0;k<8;k++) {  //8个方向 
					bool ok = true;
					int x=i, y=j, t;
					for(t=1;t<=6;t++) {
						x+=dx[k], y+=dy[k];
						if(x<1||x>N||y<1||y>N || A[x][y]!=target[t]) {
							ok=false;
							break;	
						}
					}
					if(ok) {  //匹配成功 
						x=i, y=j;
						for(t=0;t<7;t++) {
							vis[x][y] = true;
							x+=dx[k], y+=dy[k];
						}
					}
				}
			}
		}
	}
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			if(vis[i][j]) printf("%c", A[i][j]);
			else printf("*");
		}
		putchar('\n');
	}
	return 0;
}
