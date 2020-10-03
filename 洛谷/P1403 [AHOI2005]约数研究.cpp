#include<iostream>
#define LL long long
using namespace std;
LL ans = 0;

int main()
{
	int N, i;
	cin>>N;
	for(i=1;i<=N;i++) {
		ans += N/i;
	}
	cout<<ans;
	return 0;
}
