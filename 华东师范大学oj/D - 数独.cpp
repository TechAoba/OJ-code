#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char temp[20][20];
int A[20][20];
bool ok=false;

void print() {
	for(int r=0;r<9;r++) {
		for(int c=0;c<9;c++) {
			printf("%d", A[r][c]);
		}
		putchar('\n');
	}
}

void add(int &r, int &c) {
	c++;
	if(c==9) r++, c=0;
} 

void sub(int &r, int &c) {
	c--;
	if(c==-1) r--, c=8;
}

void dfs(int r, int c) {
	if(ok) return;
	if(A[r][c]!=0) {
		add(r, c);
		dfs(r, c);
		return;
	}
	if(r==9 && c==0) {
		ok=true;
		print();
	}
	int f[10] = {false};
	int i, j, h, l;
	for(i=0;i<9;i++) {
		f[A[r][i]] = f[A[i][c]] = true;
	}
	h=r/3, l=c/3;
	for(i=3*h;i<3*h+3;i++) {
		for(j=3*l;j<3*l+3;j++) {
			f[A[i][j]] = true;
		}
	}
	for(i=1;i<10;i++) {
		if(f[i]) continue;
		A[r][c] = i;
		add(r, c);
		dfs(r, c);
		sub(r, c);
		A[r][c] = 0;
	}
}

int main()
{
	int T, r, c;
	cin>>T;
	getchar();
	while(T--) {
		ok=false;
		for(r=0;r<9;r++) scanf("%s", temp[r]);
		for(r=0;r<9;r++) {
			for(c=0;c<9;c++) {
				A[r][c] = temp[r][c]^48;
			}
		}
		dfs(0, 0);
	}
	return 0;
 } 
