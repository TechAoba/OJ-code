#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;

int main()
{
	LL a;
	while(scanf("%lld", &a) != EOF) {
		printf("%lld\n\n", (a+1)*a/2);
	} 
	return 0;
}
