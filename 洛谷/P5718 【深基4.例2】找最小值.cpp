#include<iostream>
#include<string>
#define Min(a,b) (a<b?a:b)
using namespace std;
int ans = 0x3f3f3f3f;

int main()
{
	int i, N, a;
	cin>>N;
	for(i=0;i<N;i++) {
		cin>>a;
		ans = Min(ans, a);
	}
	cout<<ans<<endl;
	return 0;
}
