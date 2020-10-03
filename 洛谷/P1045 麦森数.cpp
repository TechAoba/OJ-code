#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define res register int
using namespace std;
int sav[505], ans[505], mul[505], N;

void fun1() {  //
	memset(sav, 0, sizeof(sav));
	for(res i=1;i<=500;i++) {
		for(res j=1;i+j-1<=500;j++) {
			sav[i+j-1] += ans[i] * mul[j];
		}
	}
	for(res i=1;i<=500;i++) {
		sav[i+1] += sav[i]/10;
		sav[i] %= 10;
	}
	memcpy(ans, sav, sizeof(ans));
}

void fun2() {  //mul×Ô³Ë 
	memset(sav, 0, sizeof(sav));
	for(res i=1;i<=500;i++) {
		for(res j=1;i+j-1<=500;j++) {
			sav[i+j-1] += mul[i] * mul[j];
		}
	}
	for(res i=1;i<=500;i++) {
		sav[i+1] += sav[i]/10;
		sav[i] %= 10;
	}
	memcpy(mul, sav, sizeof(mul));
}

int main()
{
	scanf("%d", &N);
	printf("%d\n", (int)((log(2)/log(10))*N+1));
	ans[1] = 1;
	mul[1] = 2;
	while(N) {
		if(N&1) fun1();
		N>>=1;
		fun2();
	}
	for(res i=500;i>=2;i--) {
		if(i!=500&&i%50==0) printf("\n%d", ans[i]);
		else printf("%d", ans[i]);
	}
	printf("%d\n", ans[1]-1);
	return 0;
}
