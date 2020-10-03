#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1005;
int A[MAXN], N, M;

int main()
{
	while(scanf("%d %d", &N, &M) != EOF) {
		int i;
		for(i=1;i<=N;i++) A[i] = i;
		for(i=1;i<M;i++) next_permutation(A+1, A+1+N);
		for(i=1;i<N;i++) printf("%d ", A[i]);
		printf("%d\n", A[N]);
	}
	return 0;
}
