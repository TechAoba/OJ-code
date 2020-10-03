#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL x, y, m, n, L, g, a, x0, y0, c;

void gcd(LL a, LL b, LL &x, LL &y) {
	if(!b) {g=a;x=1;y=0;return;}
	gcd(b, a%b, y, x);
	y -= x*(a/b);
}

int main()
{
	scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &L);
	a = m-n, c = y-x;
	if(a<0) a=-a, c=-c;
	gcd(a, L, x0, y0);
	if(c%g) printf("Impossible\n");
	else printf("%lld\n", ((x0*c/g)%(L/g)+(L/g))%(L/g));
	return 0;
}
