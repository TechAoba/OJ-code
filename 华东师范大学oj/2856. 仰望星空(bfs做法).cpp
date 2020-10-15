#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
bool vis[1006][87];
int R, C, ans;
char Map[1005][87];

struct node{
	int r, c;
	node(int r, int c):r(r),c(c){}
};

int main()
{
	int r, c;
	while(scanf("%d %d", &C, &R) != EOF) {
		memset(vis, false, sizeof(vis));
		ans = 0;
		for(r=0;r<R;r++) scanf("%s", Map[r]);
		for(r=0;r<R;r++) {
			for(c=0;c<C;c++) {
				if(!vis[r][c] && Map[r][c]=='*') {
					ans++;
					// bfs
					queue<node> que;
					vis[r][c] = true;
					que.push(node(r, c));
					
					while(!que.empty()) {
						node temp = que.front();
						que.pop();
						for(int nr=temp.r-1;nr<=temp.r+1;nr++) {
							if(nr<0||nr>=R) continue;
							for(int nc=temp.c-1;nc<=temp.c+1;nc++) {
								if(nc<0||nc>=C) continue;
								if(!vis[nr][nc] && Map[nr][nc]=='*') {
									vis[nr][nc] = true;
									que.push(node(nr, nc));
								}
							}
						}
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
