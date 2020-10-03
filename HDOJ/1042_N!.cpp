#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N, l, A[100000];

void mul(int a) {
	int i;
	for(i=0;i<l;i++) A[i] *= a;
	for(i=0;i<l;i++) {
		A[i+1] += A[i]/10;
		A[i] %= 10;
	}
	while(A[l]) {
		A[l+1] += A[l]/10;
		A[l++] %= 10;
	}
}

int main()
{
	while(scanf("%d", &N)!=EOF) {
		memset(A, 0, sizeof(A));
		A[0] = l = 1;
		for(int i=2;i<=N;i++) mul(i);
		for(int i=l-1;i>=0;i--) printf("%d", A[i]);
		putchar('\n');
	}
	return 0;
}
