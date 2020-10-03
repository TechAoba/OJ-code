#include<iostream>
#define LL long long
using namespace std;
LL ans = 0;

int main()
{
	int N, t, i;
	cin>>N>>t;
	for(i=1;i<=N;i++) {
		int tmp = i;
		while(tmp) {
			int T = tmp%10;
			if(T==t) ans++;
			tmp /= 10;
		}
	}
	cout<<ans;
	return 0;
}
