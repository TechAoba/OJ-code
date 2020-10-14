#include<iostream>
#define LL long long
#include<cstdio>
using namespace std;
LL MOD;

LL mul(LL a, LL b) {
	LL ans = 0;
	while(b) {
		if(b&1) {
			ans = (ans+a) % MOD;
		} 
		a = (a<<1) % MOD;
		b >>= 1;
	}
	return ans;
}

LL pow(LL a, LL b) {
	LL ans = 1;
	while(b) {
		if(b&1) ans = (ans*a) % MOD;
		a = mul(a, a) % MOD;
		b >>= 1; 
	}
	return ans;
} 

int main()
{
	LL a, b;
	while(scanf("%lld %lld %lld", &a, &b, &MOD) != EOF) {
		if(!(a|b|MOD)) break;
		printf("%lld\n", pow(a, b));
	}
	return 0;
} 
