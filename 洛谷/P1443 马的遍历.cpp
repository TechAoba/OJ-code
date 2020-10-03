#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
int R, C, str, stc;
int A[405][405];
int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};

struct Node{
	int x, y, step;
	Node():x(0),y(0),step(0){}
	Node(int x, int y, int step):x(x),y(y),step(step) {}
}; 

int main()
{
	memset(A, -1, sizeof(A));
	cin>>R>>C>>str>>stc;
	queue<Node> Q;
	Q.push(Node(str, stc, 0));
	Node T;
	int r, c, nr, nc, i;
	while(!Q.empty()) {
		T = Q.front(); Q.pop();
		r=T.x, c=T.y;
		if(A[r][c]!=-1) continue;
		A[r][c] = T.step;
		for(i=0;i<8;i++) {
			nr = r+dr[i], nc = c+dc[i];
			if(nr>0 && nr<=R && nc>0 && nc<=C && A[nr][nc]==-1) {
				Q.push(Node(nr, nc, T.step+1));
			}
		}
	}
	for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			printf("%-5d", A[r][c]);
		}
		putchar('\n');
	}
	return 0;
}
