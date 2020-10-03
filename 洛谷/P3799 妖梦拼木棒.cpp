#include<iostream>
#include<cstring>
#include<cstdio> 
#define LL long long
using namespace std;
LL A[5005], B[10005], N;
const LL MOD = 1e9+7;

inline LL CN2(int n) {
	return n*(n-1)/2;
}

int main()
{
	memset(A, 0, sizeof(A));
	memset(B, 0, sizeof(B));
	LL i, j, a, ans=0;
	scanf("%lld", &N);
	for(i=1;i<=N;i++) {
		scanf("%lld", &a);
		A[a]++;
	}
	for(i=1;i<=5000;i++) {
		for(j=1;j<=i/2;j++) {
			if(j!=i-j) B[i] += A[j] * A[i-j];
			else B[i] += CN2(A[j]);
		}
	}
	//for(i=1;i<10;i++) cout<<i<<"  "<<B[i]<<endl; 
	for(i=1;i<=5000;i++) {
		if(A[i]>=2) ans = (ans + CN2(A[i]) * B[i]) % MOD;
	}
	printf("%lld\n", ans);
	return 0;
}
