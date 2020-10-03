#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 150;
int N, A[2][MAXN];

int main()
{
	int i, j, k;
	while(scanf("%d", &N) != EOF) {
		for(i=0;i<=N;i++) A[0][i] = 1, A[1][i] = 0;
		for(i=2;i<=N;i++) {  //第i个因式 
			for(j=0;j<=N;j++) {
				for(k=0; k+j <= N ;k += i) A[1][k+j] += A[0][j];
			}
			memcpy(A[0], A[1], sizeof(A[1]));
			memset(A[1], 0, sizeof(A[1]));
		}
		printf("%d\n", A[0][N]);
	}
	return 0;
}
