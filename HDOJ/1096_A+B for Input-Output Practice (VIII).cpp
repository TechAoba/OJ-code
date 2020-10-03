#include<iostream>
using namespace std;

int main()
{
	int T, N, ans, add;
	cin>>T;
	for(int k=1;k<=T;k++) {
		ans = 0;
		cin>>N;
		for(int i=1;i<=N;i++) {
			cin>>add;
			ans += add;
		}
		if(k>1) cout<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
