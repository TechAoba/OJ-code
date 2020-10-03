#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	int T, N;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		double ans = 0.0;
		for(int i=2;i<=N;i++) ans += log10((double)i);
		printf("%d\n", (int)(ans+1));
	}
	return 0;
 } 
