#include<iostream>
#define Min(a,b) (a<b?a:b)
using namespace std;

int main()
{
	int N, i, num[4], val[4], ans = 0x3f3f3f3f;
	cin>>N;
	for(i=1;i<=3;i++) {
		cin>>num[i]>>val[i];
	}
	for(i=1;i<=3;i++) {
		int t = N/num[i];
		if(t*num[i]<N) t++;
		ans = Min(ans, t*val[i]);
	}
	cout<<ans;
	return 0;
}
