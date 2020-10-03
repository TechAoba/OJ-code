#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cctype>
using namespace std;
const int MAXN = 105;
int R, C, cnt = 0, ans;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
bool ok, vis[MAXN][MAXN];
char A[MAXN][MAXN];

struct Node{
	int r, c, step;
	bool operator <(Node a)const{
		return step>a.step;
	}
	Node(int r, int c, int step):r(r),c(c),step(step){}
	Node():r(0),c(0),step(0){}
};

Node node[MAXN*MAXN], last[MAXN][MAXN];

void print(int r, int c) {  //输出结果 
	int lr = last[r][c].r, lc = last[r][c].c;
	if(!(lr==0 && lc==0)) {  //上一个点非起点 
		print(lr, lc);
	}
	if(A[lr][lc]=='.') {
		printf("%ds:(%d,%d)->(%d,%d)\n", ++cnt, lr, lc, r, c);
	}
	else {
		int num = A[lr][lc] - '0';
		while(num--) {
			printf("%ds:FIGHT AT (%d,%d)\n", ++cnt, lr, lc);
		}
		printf("%ds:(%d,%d)->(%d,%d)\n", ++cnt, lr, lc, r, c);
	}
}

void bfs() {
	priority_queue<Node> Q;
	Q.push(Node(0, 0, 0));
	while(!Q.empty()) {
		Node T = Q.top(); Q.pop();
		int step = T.step, r=T.r, c=T.c;
		if(r==R-1 && c==C-1) {  //拯救公主 
			ok = true;
			cnt = 0;  //时间 
			ans = step;
			break;
		}
		for(int i=0;i<4;i++) {
			int nr = r+dr[i], nc = c+dc[i];
			if(nr<0 || nr>=R || nc<0 || nc>=C) continue;  //越界
			if(A[nr][nc] == 'X' || vis[nr][nc]) continue;  //不可达或访问过
			/*可达*/
			vis[nr][nc] = 1;  //设置访问过 
			int nstep;
			if(A[nr][nc] == '.') {  //走一步 
				nstep = step + 1;
			}
			else {  //数字 
				nstep = step + A[nr][nc]-'0'+1;
			}
			last[nr][nc].r = r;
			last[nr][nc].c = c;
			Q.push(Node(nr, nc, nstep));  //push 
		}
	}
}

int main()
{
	int r, c;
	while(scanf("%d %d", &R, &C) != EOF) {
		memset(vis, 0, sizeof(vis));
		for(r=0;r<R;r++) scanf("%s", A[r]);
		ok = false;
		bfs();
		if(!ok) printf("God please help our poor hero.\n");
		else {
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", ans);
			print(R-1, C-1);
			if(isdigit(A[R-1][C-1])) {
				int num = A[R-1][C-1] - '0';
				while(num--) {
					printf("%ds:FIGHT AT (%d,%d)\n", ++cnt, R-1, C-1);
				}
			}
		}
		printf("FINISH\n");
	}
	return 0;
} 
