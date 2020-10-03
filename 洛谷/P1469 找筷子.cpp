#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	int N, ans=0, a;
	scanf("%d", &N);
	for(register int i=0;i<N;i++) {
		scanf("%d", &a);
		ans ^= a;
	}
	printf("%d\n", ans);
	return 0;
}
