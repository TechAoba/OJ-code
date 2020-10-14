#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL A[25][25];


int main()
{
	int i, j, n;
	for(i=1;i<21;i++) {
		A[i][1] = A[i][i] = 1;
	}
	for(i=3;i<21;i++) {
		for(j=2;j<i;j++) {
			A[i][j] = A[i-1][j-1] + A[i-1][j];
		}
	}
	cin>>n;
	for(i=1;i<=n;i++) {
		for(j=1;j<=i;j++) {
			printf("%d%c", A[i][j], i==j?'\n':' ');
		}
	}
	return 0;
}
