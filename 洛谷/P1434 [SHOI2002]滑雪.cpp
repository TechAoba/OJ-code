#include<iostream>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
int A[105][105], val[105][105], R, C;
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int ans = -1;

int dfs(int r, int c) {
	if(val[r][c]>0) return val[r][c];
	int T[4] = {0};
	int Tmax = 1;
	for(int i=0;i<4;i++) {
		int nr = r+dr[i];
		int nc = c+dc[i];
		if(nr<1||nr>R||nc<1||nc>C) continue;
		if(A[nr][nc]>=A[r][c]) continue;
		if(val[nr][nc]>0) T[i] = val[nr][nc]+1;
		else T[i] = dfs(nr, nc)+1;
	}
	for(int  i=0;i<4;i++) Tmax = Max(Tmax, T[i]);
	val[r][c] = Tmax;
	//cout<<"   "<<Tmax<<endl;
	ans = Max(ans, Tmax);
	return Tmax;
}

int main()
{
	memset(val, -1, sizeof(val));
	int i, j;
	cin>>R>>C;
	for(i=1;i<=R;i++) {
		for(j=1;j<=C;j++) {
			cin>>A[i][j];
		}
	}
	for(i=1;i<=R;i++) {
		for(j=1;j<=C;j++) {
			val[i][j] = dfs(i, j);
		}
	}
	/*for(i=1;i<=R;i++) {
		for(j=1;j<=C;j++) {
			cout<<val[i][j];
		}
		cout<<endl;
	}*/
	cout<<ans;
	return 0;
}
