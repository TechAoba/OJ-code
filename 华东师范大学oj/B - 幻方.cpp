#include<iostream>
#include<cstring>
using namespace std;
int A[50][50], N, r, c, R, C, cnt, i;

void fun(int &r, int &c) {
	if(A[r][c]==0) return;
	int r1=r,c1=c;
	if(r1==1&&c1==C) {  //在右上角 
		r1=R,c1=1;
	}
	else if(r1==1) {  //在最上方 
		r1=R, c1++;
	}
	else if(c1==C) {  //在最右方 
		c1=1, r1--;
	}
	else {  //直接往右上走 
		r1--,c1++;
	}
	if(A[r1][c1]==0) {
		r=r1, c=c1;
	}
	else {  //已有数字 
		r++;
		fun(r, c);
	}
}

int main()
{
	memset(A, 0, sizeof(A));
	cin>>N;
	R = C = 2*N-1;
	r=1, c = N;
	cnt = R*R;
	for(i=1;i<=cnt;i++) {
		A[r][c] = i;
		fun(r, c);
	}
	for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			printf("%d%c", A[r][c], c==C?'\n':' ');
		}
	}
	return 0;
}
