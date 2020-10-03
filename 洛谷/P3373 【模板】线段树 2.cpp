#include<iostream>
#include<cstdio>
#include<cstring>
#define res register int
using namespace std;
const int MAXN = 1e5+10;
int num[MAXN], N, M, MOD;
inline int read() {
	int x=0, f=1;
	char c = getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	N=read(),M=read(),MOD=read();
	res i;
	int op, x, y, k;
	for(i=1;i<=N;i++) num[i] = read();
	for(i=1;i<=M;i++) {
		op = read();
		
	}
	return 0;
}
