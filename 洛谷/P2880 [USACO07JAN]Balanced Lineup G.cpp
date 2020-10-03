#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define res register int 
using namespace std;
const int MAXN = 50005, INF = 0x3f3f3f3f, FINF = -0x3f3f3f3f;
int Tmax[MAXN][17], Tmin[MAXN][17], N, M;  //从16开始 

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	N=read(), M=read();
	res i, j;
	for(i=1;i<=N;i++) {
		Tmax[i][0] = Tmin[i][0] = read();
	}
	for(j=1;(1<<j)<=N;j++) {
		for(i=1;i<=N;i++) {
			if(i+(1<<(j-1))<=N) {
				Tmax[i][j] = Max(Tmax[i][j-1], Tmax[i+(1<<(j-1))][j-1]);
				Tmin[i][j] = Min(Tmin[i][j-1], Tmin[i+(1<<(j-1))][j-1]);
			}
		}
	}
	int a, b;
	for(i=0;i<M;i++) {  //M次询问 
		int ttmax = FINF, ttmin = INF;
		a = read(), b = read();
		for(j=16;j>=0;j--) {
			if(a+(1<<j)<=b+1) {
				ttmax = Max(ttmax, Tmax[a][j]);
				ttmin = Min(ttmin, Tmin[a][j]);
				a += (1<<j);
			}
		}
		printf("%d\n", ttmax-ttmin);
	}
	return 0;
}
