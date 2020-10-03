#include<iostream>
#include<cstdio>
#include<cstring>
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
#define res register int
using namespace std;
const int MAXN = 505;
int A[MAXN][MAXN], l1[MAXN][MAXN], r1[MAXN][MAXN], R, C, ans;
bool vis[MAXN][MAXN]; 
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
inline int read() {
	int x=0,f=1;
	char c = getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

void dfs(int r, int c) {
	for(int i=0;i<4;i++) {
		int nr = r+dr[i], nc = c+dc[i];
		if(nr>R||nr<1||nc>C||nc<1||A[r][c]<=A[nr][nc]) continue;
		if(!vis[nr][nc]) {
			vis[nr][nc] = true;
			dfs(nr, nc);
		}
		l1[r][c] = Min(l1[r][c], l1[nr][nc]);
		r1[r][c] = Max(r1[r][c], r1[nr][nc]);
	}
}

int main()
{
	res r, c, i, j;
	R = read(), C = read();
	for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			A[r][c] = read();
			l1[r][c] = 0x3f3f3f3f, r1[r][c] = -1;
		}
	}
	for(c=1;c<=C;c++) {
		for(i=c;i>1;i--) if(A[R][i-1]>=A[R][i]) break;
		for(j=c;j<C;j++) if(A[R][j+1]>=A[R][j]) break;
		l1[R][c] = i;  r1[R][c] = j;
		//printf("%d  %d  %d\n", c, l1[R][c], r1[R][c]);
	}
	ans = C;
	for(c=1;c<=C;c++) {
		if(!vis[1][c]) {
			vis[1][c] = true;
			dfs(1, c);
		}
	}
	for(c=1;c<=C;c++) {
		if(vis[R][c]) {
			ans--;
		}
	}
	if(ans) {  //不能完成 
		printf("0\n%d\n", ans);
	}
	else {
		ans = 0;
		int tl = 1, tr = 1;
		while(tr<C) {
			ans++;
			for(c=1;c<=C;c++) {
				if(l1[1][c]<=tl) {
					tr = Max(tr, r1[1][c]);
				}
			}
			tl = tr+1;
		}
		printf("1\n%d\n", ans);
	}
	return 0;
}
