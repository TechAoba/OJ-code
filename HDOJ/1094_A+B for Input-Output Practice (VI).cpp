#include<iostream>
#include<cstdio>
#include<cstring>
#define res register int 
using namespace std;
int ans, N, add;


int main()
{
	res i;
	while(scanf("%d", &N) != EOF) {
		ans = 0;
		for(i=0;i<N;i++) {
			scanf("%d", &add);
			ans += add;
		}
		printf("%d\n", ans);
	}
	return 0;
}
