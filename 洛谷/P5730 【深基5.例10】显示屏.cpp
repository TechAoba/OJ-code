#include<iostream>
#include<cstdio>
using namespace std;
char ans[5][420];

void draw(int st, int num) {
	int i;
	if(num==0) {
		ans[1][st+1]=ans[2][st+1]=ans[3][st+1]='.';
	}
	else if(num==1) {
		for(i=0;i<5;i++) {
			ans[i][st]=ans[i][st+1]='.';
		}
	}
	else if(num==2) {
		ans[1][st]=ans[1][st+1]=ans[3][st+1]=ans[3][st+2]='.';
	}
	else if(num==3) {
		ans[1][st]=ans[1][st+1]=ans[3][st+1]=ans[3][st]='.';
	}
	else if(num==4) {
		ans[0][st+1]=ans[1][st+1]=ans[3][st]=ans[3][st+1]=ans[4][st]=ans[4][st+1]='.';
	}
	else if(num==5) {
		ans[1][st+2]=ans[1][st+1]=ans[3][st+1]=ans[3][st]='.';
	}
	else if(num==6) {
		ans[1][st+1]=ans[1][st+2]=ans[3][st+1]='.';
	}
	else if(num==7) {
		for(i=1;i<5;i++) {
			ans[i][st]=ans[i][st+1]='.';
		}
	}
	else if(num==8) {
		ans[1][st+1]=ans[3][st+1]='.';
	}
	else if(num==9) {
		ans[1][st+1]=ans[3][st]=ans[3][st+1]='.';
	}
}

int main()
{
	int i, j, N, a;
	for(i=0;i<5;i++) {
		for(j=0;j<420;j++) {
			ans[i][j] = 'X';
		}
	}
	cin>>N;
	for(i=3;i<420;i+=4) {
		for(j=0;j<5;j++) {
			ans[j][i] = '.';
		}
	}
	char A[105];
	scanf("%s", A);
	for(i=0;i<N;i++) {
		a = A[i]^48;
		draw(i*4, a);
	}
	for(i=0;i<5;i++) {
		for(j=0;j<4*N-1;j++) {
			printf("%c", ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
