#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define LL long long
using namespace std;
LL gcd(LL a, LL b) {
	return a%b==0?b:gcd(b, a%b);
}

int main()
{
	LL a, b, c, chang, duan;
	scanf("%lld %lld %lld", &a, &b, &c);
	chang = Max(a, Max(b, c));
	duan = Min(a, Min(b, c));
	LL G = gcd(chang, duan);
	printf("%lld/%lld\n", duan/G, chang/G); 
	return 0;
 }
