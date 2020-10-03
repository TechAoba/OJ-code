#include<iostream>
#include<algorithm>
#include<cstdio>
#define res register int
using namespace std;
const int MAXN = 1000000+5;
int N;
double X[MAXN], Y[MAXN];

int main()
{
	while(scanf("%d", &N) != EOF) {
		if(!N) break;
		res i;
		for(i=0;i<N;i++) scanf("%lf %lf", &X[i], &Y[i]);
		sort(X, X+N);
		sort(Y, Y+N);
		printf("%.2lf %.2lf\n", X[(N-1)/2], Y[(N-1)/2]);
	}
	return 0;
 } 
