#include<iostream>
#include<cstdio>
#define LL long long
#include<cstring>
using namespace std;

int main()
{
	LL T, N;
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld", &N);
		if(N==1) printf("1\n");
		else printf("%lld\n", N*(N-1));
	}
	return 0;
}
