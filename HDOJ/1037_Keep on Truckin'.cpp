#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if(A<=168) {
		printf("CRASH %d\n", A);
	}
	else if(B<=168) {
		printf("CRASH %d\n", B);
	}
	else if(C<=168) {
		printf("CRASH %d\n", C);
	}
	else {
		printf("NO CRASH\n");
	}
	return 0;
}
