#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int l=1, A[1000]={1}, N;
bool sel[10000];

void mul(int a) {
	int i;
	for(i=0;i<l;i++) A[i] *= a;
	for(i=0;i<l;i++) A[i+1] += A[i]/10, A[i] %= 10;
	while(A[l]) {
		A[l+1] += A[l]/10;
		A[l++] %= 10;
	}
} 

int main()
{
	scanf("%d", &N);
	int i;
	bool st = 0;
	for(i=2;N>0;i++) {
		sel[i] = 1;
		N -= i;
	}
	if(N==-1) {
		sel[2] = 0;
		sel[i-1] = 0;
		sel[i] = 1;
	}
	else if(N<0) {
		sel[-N] = 0;
	}
	for(i=2;i<10000;i++){
		if(sel[i]) {
			if(st) putchar(' ');
			st = 1;
			printf("%d", i);
			mul(i);
		}
	} 
	putchar('\n');
	for(i=l-1;i>=0;i--) printf("%d", A[i]);
	return 0;
}
