#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int A[1005];

int main()
{
	int N;
	while(scanf("%d", &N)==1 && N>0) {
		int up = 0, down = 0, i;
		for(i=1;i<=N;i++) {
			scanf("%d", &A[i]);
			if(A[i]>A[i-1]) up += A[i]-A[i-1];
			else if(A[i]<A[i-1]) down += A[i-1]-A[i];
		}
		printf("%d\n", up*6+down*4+N*5);
	}
	return 0;
}
