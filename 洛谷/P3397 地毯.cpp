#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 1005;
int A[MAXN][MAXN], N, M;

int main()
{
	scanf("%d %d", &N, &M);
	int i, j, x1, x2, y1, y2;
	for(i=1;i<=M;i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		A[x1][y1]++;
		A[x2+1][y2+1]++;
		A[x2+1][y1]--;
		A[x1][y2+1]--;
	}
	for(i=1;i<=N;i++) {
		for(j=1;j<=N;j++) {
			A[i][j] += A[i-1][j]+A[i][j-1]-A[i-1][j-1];
			printf("%d%c", A[i][j], j==N?'\n':' ');
		}
	}
	return 0;
}
