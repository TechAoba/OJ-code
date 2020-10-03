#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
using namespace std;
LL N, K, MOD;

int main()
{
	scanf("%lld %lld %lld", &MOD, &N, &K);
	printf("%lld\n", ((N%MOD)*(K%MOD)) % MOD);
	return 0;
}
