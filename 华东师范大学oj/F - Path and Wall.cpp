#include<iostream>
#include<cstring>
#include<cstdio>
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
using namespace std;
int C, S, Q;//C个小站，S条通路和Q次冒险
int A[105][105];
const int INF = 0x3f3f3f3f;

inline int read() {
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x;
}

int main()
{
	int i, j, k, a, b, l, kase=1;
	bool ok = false;
	while(1) {
		C=read(),S=read(),Q=read();
		if(C==0&&S==0&&Q==0)break;
		for(i=0;i<101;i++) {
			for(j=0;j<105;j++) A[i][j] = INF;
		}
		for(i=0;i<S;i++) {
			a=read(),b=read(),l=read();
			A[a][b] = A[b][a] = l;
		}
		for(k=1;k<=C;k++) {
			for(i=1;i<=C;i++) {
				if(i==k) continue;
				for(j=1;j<=C;j++) {
					if(j==k||j==i) continue;
					A[i][j] = Min(A[i][j], Max(A[i][k],A[k][j]));
					A[j][i] = A[i][j];
				}
			}
		}
		if(ok) cout<<endl;
		ok = true;
		printf("Case #%d\n", kase++);
		for(i=0;i<Q;i++) {
			a=read(),b=read();
			if(A[a][b]==INF) printf("no path\n");
			else printf("%d\n", A[a][b]);
		}
	}
	return 0;
}
