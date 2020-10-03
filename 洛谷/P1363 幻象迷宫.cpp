#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 1505;
bool vis[MAXN][MAXN], wall[MAXN][MAXN], ok=false;
int R, C, X[MAXN][MAXN], Y[MAXN][MAXN];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int r, int c, int rr, int cc) {  //r和c表示取模 
	if(ok) return;
	if(vis[r][c] && (X[r][c]!=rr||Y[r][c]!=cc)) {
		ok=true;
		return;
	}
	vis[r][c]=true;X[r][c]=rr; Y[r][c]=cc;
	int r1, c1, rr1, cc1, i;
	for(i=0;i<4;i++) {
		r1=(r+dr[i]+R)%R; c1=(c+dc[i]+C)%C;
		rr1=rr+dr[i]; cc1=cc+dc[i];
		if(!wall[r1][c1] && (!vis[r1][c1] || X[r1][c1]!=rr1 || Y[r1][c1]!=cc1)) {
			dfs(r1, c1, rr1, cc1);
		}
	}
}

int main()
{
	int r, c, str, stc;
	char ch;
	while(cin>>R>>C) {
		ok=false;
		memset(wall, 0, sizeof(wall));
		memset(vis, 0, sizeof(vis));
		memset(X, 0, sizeof(X));
		memset(Y, 0, sizeof(Y));
		for(r=0;r<R;r++) {
			for(c=0;c<C;c++) {
				cin>>ch;
				if(ch=='#') wall[r][c] = true;
				else if(ch=='S') str=r, stc=c;
			}
		}
		dfs(str, stc, str, stc);
		if(ok) printf("Yes\n");
        else printf("No\n");
	}
	return 0;
 } 
