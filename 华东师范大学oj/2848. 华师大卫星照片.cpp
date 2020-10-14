#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
char A[1005][1005];
int R, C, ans=0, T=0;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void dfs(int r, int c) {
	T++;
	A[r][c] = '.';
	for(int i=0;i<4;i++) {
		int nr = r+dr[i];
		int nc = c+dc[i];
		if(nr<0||nc<0||nr>=R||nc>=C||A[nr][nc]=='.') continue;
		dfs(nr, nc);
	}
}

int main()
{
	cin>>C>>R;
	int r, c;
	for(r=0;r<R;r++) {
		scanf("%s", A[r]);
	}
	for(r=0;r<R;r++) {
		for(c=0;c<C;c++) {
			T = 0;
			if(A[r][c] == '*') dfs(r, c);
			ans = Max(ans, T);
		}
	}
	cout<<ans<<endl;
	return 0;
}
