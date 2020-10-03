#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

inline int gcd(int a, int b) {
	return b==0?a:gcd(b, a%b);
}

int main()
{
	int a, b;
	while(scanf("%d %d", &a, &b) != EOF) {
		printf("%d\n", a/gcd(a, b)*b);
	}
	return 0;
}
