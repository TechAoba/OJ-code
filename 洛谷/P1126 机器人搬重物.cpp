#include<iostream>
#include<cstdio>
#include<queue>
#define res register int
using namespace std;
bool vis[55][55][4];
int A[55][55], R, C, str, stc, enr, enc;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
struct Node{
	int r, c, dir, step;
	Node(int r, int c, int dir, int step):r(r),c(c),dir(dir),step(step){}
	Node():r(0),c(0),dir(0),step(0){}
};
queue<Node> Q; 

int main()
{
	scanf("%d %d", &R, &C);
	int r, c;
	char ch;
	for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			scanf("%d", &A[r][c]);
		}
	}
	scanf("%d %d %d %d %c", &str, &stc, &enr, &enc, &ch);
	if(str==enr && stc==enc) {
		cout<<0;
		return 0;
	}
	if(ch=='N') Q.push(Node(str, stc, 0, 0)), vis[str][stc][0]=1;
	else if(ch=='E') Q.push(Node(str, stc, 1, 0)), vis[str][stc][1]=1;
	else if(ch=='S') Q.push(Node(str, stc, 2, 0)), vis[str][stc][2]=1;
	else if(ch=='W') Q.push(Node(str, stc, 3, 0)), vis[str][stc][3]=1;
	while(!Q.empty()) {
		Node T = Q.front(); Q.pop();
		res r=T.r,c=T.c,dir=T.dir,step=T.step;
		for(res i=1;i<=3;i++) {  //×ß1£¬ 2£¬ 3²½ 
			res nr = r+dr[dir]*i, nc = c+dc[dir]*i;
			if(nr<1 || nc<1 || nr>=R || nc>=C || A[nr][nc] || A[nr+1][nc] || A[nr][nc+1] || A[nr+1][nc+1]) {
				break;
			}
			else if(nr==enr && nc==enc) {
				cout<<step+1;
				return 0;
			}
			if(!vis[nr][nc][dir]) {
				vis[nr][nc][dir] = true;
				Q.push(Node(nr, nc, dir, step+1));
			}
		}
		int dir1 = (dir+1)%4;
		int dir2 = (dir+3)%4;
		if(!vis[r][c][dir1]) {
			vis[r][c][dir1] = true;
			Q.push(Node(r, c, dir1, step+1));
		}
		if(!vis[r][c][dir2]) {
			vis[r][c][dir2] = true;
			Q.push(Node(r, c, dir2, step+1));
		}
	}
	cout<<-1;
	return 0;
}
