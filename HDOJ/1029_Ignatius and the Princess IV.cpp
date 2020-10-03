#include<iostream>
#include<cstdio>
#define res register int
using namespace std;

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	int N;
	while(scanf("%d", &N) != EOF) {
		res i;
		int cnt = 0, now=0, a;
		for(i=0;i<N;i++) {
			a = read();
			if(now != a) {
				cnt--;
				if(cnt<0) {
					cnt = 1;
					now = a;
				}
			}
			else {
				cnt++;
			}
		}
		printf("%d\n", now);
	}
	return 0;
}
