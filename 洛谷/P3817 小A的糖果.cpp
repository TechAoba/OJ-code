#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
int N, M;

int main()
{
	int i, last, now, sub;
	LL ans = 0;
	scanf("%d %d %d", &N, &M, &last);
	for(i=2;i<=N;i++) {
		scanf("%d", &now);
		if(last>=M) {
			sub = last+now-M;
			ans += sub;
			//printf("ddd%d\n", sub);
			last = 0;
		}
		else if(last+now>M) {
			sub = last+now-M;
			//printf("ddd%d\n", sub);
			ans += sub;
			last = now-sub;
		}
		else last = now;
	}
	printf("%lld\n", ans);
	return 0;
}
