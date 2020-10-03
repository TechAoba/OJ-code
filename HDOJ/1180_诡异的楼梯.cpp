#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define Min(a,b) (a<b?a:b)
using namespace std;
int vis[25][25], R, C, str, stc, enr, enc;
char Map[25][25];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
struct Node{
	int r, c, step;
	bool operator <(const Node &a)const{
		return step>a.step;
	}
	Node(int r, int c, int step):r(r),c(c),step(step){}
	Node():r(0),c(0),step(0){}
};

inline bool ok(int nr, int nc) {
	if(nr<1||nr>R||nc<1||nc>C||Map[nr][nc]=='*') return 0;
	return 1;
}

void bfs() {
	priority_queue<Node> Q; 
	Q.push(Node(str, stc, 0));
	vis[str][stc] = 0;
	int ans = 0x3f3f3f3f;
	while(!Q.empty()) {
		Node T = Q.top(); Q.pop();
		int tr = T.r, tc = T.c, step = T.step;
		if(tr==enr && tc==enc) {
			ans = Min(ans, step);
			continue;
		}
		/*  --偶数步可以左右走  |偶数步可以上下走  */
		for(int i=0;i<4;i++) {  //i&1==true 表示左右走 
			int nr = tr+dr[i];
			int nc = tc+dc[i];
			if(!ok(nr, nc)) continue;
			if(Map[nr][nc] == '-') {
				int rr = nr+dr[i];
				int cc = nc+dc[i];
				if(!ok(rr, cc)) continue;
				if((step+i)&1) {  //符合条件 
					if(step+1<vis[rr][cc]) {
						vis[rr][cc] = step+1;
						Q.push(Node(rr, cc, step+1)); 
						//printf("%d %d  过桥->  %d %d\n", tr, tc, rr, cc);
					}
				}
				else {  //等一分钟 
					if(step+2<vis[rr][cc]) {
						vis[rr][cc] = step+2;
						Q.push(Node(rr, cc, step+2));
						//printf("%d %d  等一秒过桥->  %d %d\n", tr, tc, rr, cc);
					}
				}
			}
			else if(Map[nr][nc] == '|') {
				int rr = nr+dr[i];
				int cc = nc+dc[i];
				if(!ok(rr, cc)) continue;
				if((step+i+1)&1) {  //符合条件 
					if(step+1<vis[rr][cc]) {
						vis[rr][cc] = step+1;
						Q.push(Node(rr, cc, step+1)); 
						//printf("%d %d  过桥->  %d %d\n", tr, tc, rr, cc);
					}
				}
				else {  //等一分钟 
					if(step+2<vis[rr][cc]) {
						vis[rr][cc] = step+2;
						Q.push(Node(rr, cc, step+2)); 
						//printf("%d %d  等一秒过桥->  %d %d\n", tr, tc, rr, cc);
					}
				}
			}
			else {
				if(step+1<vis[nr][nc]) {
					vis[nr][nc] = step+1;
					Q.push(Node(nr, nc, step+1)); 
					//printf("%d %d %c  ->  %d %d %c\n", tr, tc, Map[tr][tc], nr, nc, Map[nr][nc]);
				}
			}
		}
	}
	printf("%d\n", ans);
}

int main()
{
	while(scanf("%d %d", &R, &C)==2) {
		memset(vis, 127, sizeof(vis));
		int r, c;
		for(r=1;r<=R;r++) scanf("%s", Map[r]+1);
		for(r=1;r<=R;r++) {
			for(c=1;c<=C;c++) {
				if(Map[r][c]=='S') str=r, stc=c;
				else if(Map[r][c]=='T') enr=r, enc=c;
			}
		}
		//cout<<"32="<<Map[3][2]<<endl;
		bfs();
	}
	return 0;
}
