#include<iostream>
using namespace std;
const int MAXN = 1e4+10;
bool prime[MAXN], vis[MAXN];
int pp[MAXN];

int fan(int num) {
	int ans=0;
	while(num) {
		ans = ans*10+num%10;
		num/=10;
	}
	return ans;
}

int main()
{
	int i, j, cnt=0, a, b, ans=0;
	for(i=2;i<MAXN;i++) {
		if(!vis[i]) pp[cnt++]=i, prime[i]=true;
		for(j=0;j<cnt && i*pp[j]<MAXN;j++) {
			vis[i*pp[j]] = true;
			if(i%pp[j]==0) break;
		}
	}
	cin>>a>>b;
	for(i=a;i<=b;i++) {
		if(prime[i] && prime[fan(i)]) ans++;
	}
	cout<<ans;
	return 0;
}
