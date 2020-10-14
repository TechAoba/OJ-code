#include<iostream>
#include<cstdio>
using namespace std;
char M[105][105];
int A[105][105], R, C, r, c, t=1, i, nr, nc;
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

int main()
{
	bool ok=false;
	while(cin>>R>>C) {
		if(R==0 && C==0) break;
		getchar();
		for(r=1;r<=R;r++) {
			for(c=1;c<=C;c++) {
				M[r][c] = getchar();
			}
			getchar();
		}
		for(r=1;r<=R;r++) {
			for(c=1;c<=C;c++) {
				if(M[r][c]=='*') A[r][c] = -1;
				else {
					A[r][c] = 0;
					for(i=0;i<8;i++) {
						nr = r+dr[i];
						nc = c+dc[i];
						if(nr<1||nr>R||nc<1||nc>C) continue;
						if(M[nr][nc]=='*') A[r][c]++;
					}
				}
			}
		}
		if(ok) putchar('\n');
		printf("Field #%d:\n", t++);
		for(r=1;r<=R;r++) {
			for(c=1;c<=C;c++) {
				if(A[r][c]==-1) printf("*");
				else printf("%d", A[r][c]);
			}
			putchar('\n');
		}
		ok=true;
	}
	return 0;
}
