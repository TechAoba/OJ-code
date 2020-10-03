#include<iostream>
#include<cstdio>
#include<cstring>
#define res register int
using namespace std;
const int MAXN = 10000005;
int num[MAXN];

int main()
{
	int jin1, jin2, t1, t2, N, val, t, x;
	res i, j, k;
	scanf("%d %d %d %d %d", &jin1, &jin2, &t1, &t2, &N);
	for(k=jin1;k<=jin2;k++) {
		for(i=1;i<k;i++) {
			for(j=0;j<k;j++) {
				if(i==j) continue;
				x = 0, t=1;
				while(x<=t2) {
					if(t) {
						x = (x*k)+i;
					}
					else {
						x = (x*k)+j;
					}
					if(x<=t2) num[x]++;
					t = 1-t;
				}
			}
		}
	}
	for(i=t1;i<=t2;i++) {
		if(num[i]==N) printf("%d\n", i);
	}
	return 0;
}
