#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int N, i, ans=0, last=0, now;
	scanf("%d", &N);
	for(i=1;i<=N;i++) {
		scanf("%d", &now);
		if(now>last) ans += now-last;
		last = now;
	}
	printf("%d\n", ans);
	return 0;
}
