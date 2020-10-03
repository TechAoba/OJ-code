#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	long long a, b;
	while(scanf("%lld %lld", &a, &b)==2 && (a|b)) {
		printf("%lld\n", a+b);
	}
	return 0;
 } 
