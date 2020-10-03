#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char A[10], B[10];

void dfs(int L1, int R1, int L2, int R2) {
	if(L1>R1) return;
	else if(L1==R1) {
		putchar(A[L1]);
		return;
	}
	char root = B[R2];
	putchar(root);
	int t = 0;
	while(A[L1+t]!=root) t++;
	dfs(L1, L1+t-1, L2, L2+t-1);
	dfs(L1+t+1, R1, L2+t, R2-1);
}

int main()
{
	scanf("%s %s", A, B);
	int len = strlen(A);
	dfs(0, len-1, 0, len-1);
	return 0;
} 
