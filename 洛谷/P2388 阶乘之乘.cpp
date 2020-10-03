#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define Min(a,b) (a<b?a:b)
using namespace std;
LL num2=0,num5=0, N;

void fun(LL a, LL bei) {
	LL add2=0, add5=0;
	while(a%2==0) {
		add2++;
		a/=2;
	}
	while(a%5==0) {
		add5++;
		a/=5;
	}
	num2 += add2*bei;
	num5 += add5*bei;
}

int main()
{
	scanf("%lld", &N);
	for(register int i=1;i<=N;i++) {
		fun(i, N-i+1);
	}
	printf("%lld\n", Min(num2, num5));
	return 0;
}
