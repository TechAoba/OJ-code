#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define LL long long
using namespace std;

bool cmp(int a, int b) {
	return a>b;
}

inline LL P(LL a, LL b) {
	LL num = 1;
	for(int i=1;i<=b;i++) num *= a;
	return num;
}

int main()
{
	char s[50];
	LL tar;
	while(scanf("%lld %s", &tar, s) != EOF) {
		if(tar==0 && strcmp("END", s)==0) break;
		int A[50] = {0};
		int len = strlen(s);
		int i, j, k, x, y;
		for(i=0;i<len;i++) A[i] = s[i] - 64;
		sort(A, A+len, cmp);
		bool ok = 1;
		for(i=0;i<len && ok;i++) {
			for(j=0;j<len && ok;j++) {
				if(i==j) continue;
				for(k=0;k<len && ok;k++) {
					if(i==k || j==k) continue;
					for(x=0;x<len && ok;x++) {
						if(i==x || j==x || k==x) continue;
						for(y=0;y<len && ok;y++) {
							if(i==y||j==y||k==y||x==y) continue;
							if(A[i]-P(A[j], 2)+P(A[k], 3)-P(A[x], 4)+P(A[y], 5) == tar) {
								ok = 0;
								printf("%c%c%c%c%c\n", A[i]+64, A[j]+64, A[k]+64, A[x]+64, A[y]+64);
							}
						}
					}
				}
			}
		}
		if(ok) printf("no solution\n");
	}
	return 0;
}
