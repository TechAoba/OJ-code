#include<iostream>
using namespace std;
const int maxn = 1e4+10;
int N, A[105];
bool vis[maxn<<1];

int main()
{
	int i, j, ans=0;
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>A[i];
		for(j=1;j<i;j++) {
			vis[A[i]+A[j]] = true;
		}
	}
	for(i=1;i<=N;i++) {
		if(vis[A[i]]) ans++;
	}
	cout<<ans;
	return 0;
}
