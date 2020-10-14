#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL A[51];

int main()
{
	int T, i, a;
	A[0] = 1;
	for(i=1;i<51;i++) {
		A[i] = 0;
		if(i-4>=0) A[i] += A[i-4];
		if(i-3>=0) A[i] += A[i-3];
		if(i-2>=0) A[i] += A[i-2];
		if(i-1>=0) A[i] += A[i-1];
	}
	cin>>T;
	for(i=0;i<T;i++) {
		cin>>a;
		printf("case #%d:\n%lld\n", i, A[a]);
	}
	return 0;
 } 
