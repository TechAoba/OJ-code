#include<iostream>
using namespace std;
bool vis[100005];
int num[100005];

inline int read() {
	int x=0;
	char c = getchar();
	while(c<'0' || c>'9') {c=getchar();}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x;
}

int main()
{
	int N, M, i, a, b, ans=1;
	vis[1] = 1;
	N=read(),M=read();
	for(i=1;i<=N;i++) num[i]=1;
	for(i=0;i<M;i++) {
		a = read();
		b = read();
		num[a]--;
		num[b]++;
		if(!vis[a]) continue;
		if(num[a]==0 && !vis[b]) {
			vis[b] = 1;
			vis[a] = 0;
		}
		else if(num[a]==0 && vis[b]) {
			ans--;
			vis[a] = 0;
			continue;
		}
		else if(num[a]>0 && !vis[b]) {
			vis[b] = 1;
			ans++;
		}
		else if(num[a]>0 && vis[b]) {
			continue;
		}
	}
	cout<<ans<<endl;
	return 0;
}
