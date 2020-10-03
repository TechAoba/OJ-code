#include<iostream>
using namespace std;
int L, N;
bool vis[10000+10];

int main()
{
	cin>>L>>N;
	int i, a, b, ans=0;
	for(i=0;i<N;i++) {
		cin>>a>>b;
		for(;a<=b;a++) {
			vis[a] = true;
		}
	}
	for(i=0;i<=L;i++) {
		if(!vis[i]) ans++;
	}
	cout<<ans;
	return 0;
}
