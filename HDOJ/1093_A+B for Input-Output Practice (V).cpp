#include<iostream>
#include<cstdio>
#include<cstring>
#define res register int 
using namespace std;
int ans, N, T, add;

int main()
{
	res i;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		ans = 0;
		for(i=0;i<N;i++) {
			scanf("%d", &add);
			ans += add;
		}
		printf("%d\n", ans);
	}
	return 0;
}
