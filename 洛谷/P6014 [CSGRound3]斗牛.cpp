#include<iostream>
#include<cstdio>
#include<cstring>
#define res register int
using namespace std;
int vis1[10], vis2[10], N, sum=0;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	N=read();
	res i, a, j;
	for(i=1;i<=N;i++) {
		a = read();
		sum += a;
		for(j=0;j<10;j++) {
			if(vis1[j]) vis2[(j+a)%10] = 1;
		}
		vis1[a%10] = 1;
	}
	//for(i=0;i<10;i++) printf("i=%d  %d  %d\n", i, vis1[i], vis2[i]);
	sum%=10;
	if(vis2[sum]) printf("%d", sum==0?10:sum);
	else putchar('0');
	return 0;
}
