#include<iostream>
#define LL long long
using namespace std;
bool vis[105];
LL A[105];

int main()
{
	A[0] = 1;
	int i, n, k, a;
	for(i=1;i<=105;i++) A[i] = 0;
	cin>>n>>k;
	for(i=0;i<k;i++) {
		cin>>a;
		vis[a] = true;
	}
	for(i=1;i<=n;i++) {
		if(vis[i]) continue;
		if(i-3>=0 && !vis[i-3]) A[i] += A[i-3];
		if(i-2>=0 && !vis[i-2]) A[i] += A[i-2];
		if(i-1>=0 && !vis[i-1]) A[i] += A[i-1];
	}
	cout<<A[n];
	return 0;
}
