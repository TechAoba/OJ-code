#include<iostream>
#include<cstdio>
#include<cstring>
#define UI unsigned int
using namespace std;
int A[32];

void rever() {
	int T[32];
	for(int i=0;i<32;i++) {
		T[i] = A[(i+16)%32];
	}
	memcpy(A, T, sizeof(A));
}

int main()
{
	UI n;
	scanf("%u", &n);
	int poi=0;
	while(n) {
		if(n&1) A[poi] = 1;
		n>>=1;
		poi++;
	}
	rever();
	n = 0;
	int quan=1;
	for(int i=0;i<32;i++) {
		if(A[i]) n += quan;
		quan<<=1;
	}
	printf("%u\n", n);
	return 0;
}
