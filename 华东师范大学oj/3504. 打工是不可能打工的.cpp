#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;
const int MAXN = 2e5+10;
int gz[MAXN], hq[MAXN];

int read() {
	int flag=1, num=0;
	char c = getchar();
	while(c<'0' || c>'9') {if(c=='-') flag=-1; c=getchar();}
	while(c>='0' && c<='9') {num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return flag*num;
}

bool cmp(int a, int b) {
	return a>b;
}

int main()
{
	int i, N, ans=0;
	LL cnt = 0;
	N=read();
	for(i=1;i<=N;i++) gz[i]=read();
	for(i=1;i<=N;i++) hq[i]=read(), cnt+=hq[i];
	sort(gz+1, gz+1+N, cmp);
	for(i=1;i<=N;i++) {
		if(cnt<=0) break;
		cnt -= gz[i];
		ans++;
	}
	if(cnt>0) cout<<"Game Over!"<<endl;
	else cout<<ans<<endl;
	return 0;
}
