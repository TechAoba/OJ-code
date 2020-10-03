#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int T, N, M;
	scanf("%d", &T);
	for(int kase=1;kase<=T;kase++) {
		printf("Scenario #%d:\n", kase);
		scanf("%d %d", &N, &M);
		if((N&1) && (M&1)) printf("%.2lf\n\n", 1.0*M*N+0.41);
		else printf("%.2lf\n\n", 1.0*M*N);
	}
	return 0;
}
