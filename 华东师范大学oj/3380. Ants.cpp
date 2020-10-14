#include<iostream>
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
#include<cstdio>
using namespace std;

int main()
{
	int T, N, i, L, a;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &L, &N);
		int Tmin = -1, Tmax = -1;
		for(i=1;i<=N;i++) {
			scanf("%d", &a);
			Tmax = Max(Tmax, Max(a, L-a));
			Tmin = Max(Tmin, Min(a, L-a));
		}
		printf("%d %d\n", Tmin, Tmax);
	}
	return 0;
}
