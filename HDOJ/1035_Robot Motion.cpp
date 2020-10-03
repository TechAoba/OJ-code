#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int step[15][15], R, C;
char A[15][15];
int dr[4] = {-1, 0, 1, 0};  //N E S W
int dc[4] = {0, 1, 0, -1};

int main()
{
	int r, c, cnt=0;
	while(scanf("%d %d", &R, &C) != EOF && (R|C)) {
		scanf("%d", &c);
		memset(step, 0, sizeof(step));
		cnt = 0;  //步数 
		for(r=1;r<=R;r++) scanf("%s", A[r]+1);
		step[1][c] = ++cnt;
		r = 1;
		while(1) {
			switch (A[r][c]) {
				case 'N':r+=dr[0],c+=dc[0];break;
				case 'E':r+=dr[1],c+=dc[1];break;
				case 'S':r+=dr[2],c+=dc[2];break;
				case 'W':r+=dr[3],c+=dc[3];break;
			}
			if((r<1||r>R||c<1||c>C) || step[r][c]) break;
			step[r][c] = ++cnt;
		}
		if(r<1||r>R||c<1||c>C) {  //出界 
			printf("%d step(s) to exit\n", cnt);
		}
		else if(step[r][c]) {
			printf("%d step(s) before a loop of %d step(s)\n", step[r][c]-1, cnt-step[r][c]+1);
		}
	}
	return 0;
} 
