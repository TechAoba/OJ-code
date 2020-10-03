#include<iostream>
#include<cstdio>
#include<map>
#define LL long long 
using namespace std;
const LL MOD = 6662333;

LL quickPow(LL a, LL b) {
	LL num = 1;
	while(b) {
		if(b&1) num = (num*a) % MOD;
		a = (a*a) % MOD;
		b >>= 1;
	}  
	return num;
}

int main()
{
	LL N;
	scanf("%lld", &N);
	N--;
	printf("%lld\n", quickPow(2, N));
	return 0;
}
