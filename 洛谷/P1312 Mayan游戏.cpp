#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int back_up[7][7][5];  //备份数组 
int A[7][5], step, ansx[6], ansy[6], answ[6];  //处理数组
bool vis[7][5];

int read() {
	int num=0;
	char c = getchar();
	while(c<'0' || c>'9') c = getchar();
	while(c>='0' && c<='9') num = (num<<3)+(num<<1)+(c^48), c=getchar();
	return num;
}

void show() {
	for(int i=6;i>=0;i--) {
		for(int j=0;j<=4;j++) {
			printf("%d%c", A[i][j], j==4?'\n':' ');
		}
	}
}

void copy(int x) {  //备份数组 
	for(int i=0;i<=6;i++) {
		for(int j=0;j<=4;j++) {
			back_up[x][i][j] = A[i][j];
		}
	}
}

inline void load(int x) {  //加载数组 
	for(int i=0;i<=6;i++) {
		for(int j=0;j<=4;j++) {
			A[i][j] = back_up[x][i][j];
		}
	}
}

void drop() {  //向下掉落 
	int r, c, t, cnt;
	for(c=0;c<5;c++) {
		cnt = 0;
		for(r=0;r<7;r++) {
			if(A[r][c]==0) cnt++;
			else {
				t = A[r-cnt][c];
				A[r-cnt][c] = A[r][c];
				A[r][c] = t;
			}
		}
	} 
}

bool ok() {  //是否全部清理完 
	for(int r=0;r<7;r++) {
		for(int c=0;c<5;c++) {
			if(A[r][c]!=0) return false;
		}
	}
	return true;
}

bool clean() {  //清理 
	memset(vis, 0, sizeof(vis));
	int r, c, t, i, j, cnt;
	for(r=0;r<7;r++) {
		for(c=0;c<=2;) {
			t = A[r][c], cnt=1;
			if(t==0) {
				c++;
				continue;
			}
			for(i=c+1;i<5;i++) {
				if(t==A[r][i]) cnt++;
				else break;
			}
			if(cnt>=3) {
				for(j=c;j<i;j++) vis[r][j] = true;
			}
			c = i;
		}
	}
	for(c=0;c<5;c++) {
		for(r=0;r<=4;) {
			t = A[r][c], cnt=1;
			if(t==0) break;
			for(i=r+1;i<7;i++) {
				if(t==A[i][c]) cnt++;
				else break;
			}
			if(cnt>=3) {
				for(j=r;j<i;j++) vis[j][c] = true;
			}
			r = i;
		}
	}
	bool flag = false;
	for(r=0;r<7;r++) {
		for(c=0;c<5;c++) {
			if(vis[r][c]) A[r][c] = 0, flag=true;
		}
	}
	return flag;
}

void dfs(int st) {
	int i, x, y, r, c, t;
	if(ok()) {
		for(i=0;i<step;i++) {
			printf("%d %d %d\n", ansx[i], ansy[i], answ[i]);
		}
		exit(0);
	}
	if(st==step) return;
	load(st);  //加载数组 
	for(x=0;x<5;x++) {
		for(y=0;y<7;y++) {
			if(A[y][x]==0) continue;
			if(x!=4) {  //向右走 
				c=x+1;
				if(A[y][x]!=A[y][c]) {
					t = A[y][x], A[y][x] = A[y][c], A[y][c] = t;  //交换
					while(true) {
						drop();
						if(!clean()) break;
					}
					copy(st+1);
					ansx[st]=x, ansy[st]=y, answ[st]=1;
					dfs(st+1);
					load(st);  //加载数组 
				}
			}
			if(x!=0) {  //向左走 
				c = x-1;
				if(A[y][c]==0) {
					t = A[y][x], A[y][x] = A[y][c], A[y][c] = t;  //交换
					while(true) {
						drop();
						if(!clean()) break;
					}
					copy(st+1);
					ansx[st]=x, ansy[st]=y, answ[st]=-1;
					dfs(st+1);
					load(st);  //加载数组 
				}
			}
		}
	}
}

int main()
{
	int i, t, cnt;
	step = read();
	for(i=0;i<5;i++) {
		cnt=0;
		while(true) {
			t = read();
			if(t==0) break;
			A[cnt++][i] = t; 
		}
	}
	copy(0);
	dfs(0);
	printf("-1\n"); 
	return 0;
}
