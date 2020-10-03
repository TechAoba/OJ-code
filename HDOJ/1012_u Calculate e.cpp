#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
double fac[11], e[11];

int main()
{
	fac[0] = fac[1] = 1;
	e[0] = 1;
	e[1] = 2;
	int i;
	for(i=2;i<10;i++) {
		fac[i] = fac[i-1] * i;
		e[i] = e[i-1] + (1/fac[i]);
	}
	printf("n e\n- -----------\n0 1\n1 2\n2 2.5\n");
	for(i=3;i<10;i++) {
		printf("%d %.9lf\n", i, e[i]);
	}
	return 0;
}
