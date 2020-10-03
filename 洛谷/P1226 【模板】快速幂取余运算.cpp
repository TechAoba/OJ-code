#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL ans = 1;

void quick_pow(LL a, LL b, LL mod) {
	int mul = a; 
	while(b>0) {
		if(b&1) {
			ans = (ans*mul)%mod;
		}
		mul = mul*mul%mod;
		b>>=1;
	}
}

int main()
{
	LL a, b, mod;
	cin>>a>>b>>mod;
	printf("%lld^%lld mod %lld=", a, b, mod);
	a %= mod;
	quick_pow(a, b, mod);
	printf("%lld", ans%mod);
	return 0;
}
