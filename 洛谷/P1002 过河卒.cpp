#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
const int maxn = 25;
int A[maxn][maxn];
bool vis[maxn][maxn] = {false};
int N, M;  //N行M列 
int posn, posm;  //马的坐标
LL ans[maxn][maxn]; 
int dm[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dn[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main()
{
	cin>>N>>M>>posn>>posm;
	int i, j;
	vis[posn][posm] = true;
	for(i=0;i<8;i++) {
		int Tn = posn + dn[i];
		int Tm = posm + dm[i];
		if(Tn>=0 && Tm>=0) vis[Tn][Tm] = true;
	}
	/*for(i=0;i<=N;i++) {
		for(j=0;j<=M;j++) {
			cout<<vis[i][j];
		}
		cout<<endl;
	}*/
	for(i=0;i<=M;i++) {  //初始化下边一行 
		vis[N][i]?ans[N][i]=0:ans[N][i]=1;
	}
	for(i=0;i<=N;i++) {  //初始化右边一列 
		vis[i][M]?ans[i][M]=0:ans[i][M]=1;
	}
	
	for(i=N-1;i>=0;i--) {
		for(j=M-1;j>=0;j--) {
			if(vis[i][j]) ans[i][j] = 0;
			else {
				ans[i][j] = ans[i+1][j] + ans[i][j+1];
			}
		}
	}
	cout<<ans[0][0];
	/*for(i=0;i<=N;i++) {
		for(j=0;j<=M;j++) {
			cout<<ans[i][j];
		}
		cout<<endl;
	}*/
	return 0;
}

//6 6 3 3

