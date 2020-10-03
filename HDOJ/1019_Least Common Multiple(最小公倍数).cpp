#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

inline int gcd(int a, int b) {
	return b==0?a:gcd(b, a%b);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		int N, i, ans = 1, a;
		scanf("%d", &N);
		for(i=0;i<N;i++) {
			scanf("%d", &a);
			ans = ans / gcd(ans, a) * a;
		}
		printf("%d\n", ans);
	}
	return 0;
}
