#include<iostream>
#define Max(a,b) (a>b?a:b)
using namespace std;

int main()
{
	int N, M, i, j, a, ans = 0;
	cin>>N>>M;
	for(i=0;i<N;i++) {
		int T = -1;
		for(j=0;j<M;j++) {
			cin>>a;
			T = Max(T, a);
		}
		ans += T;
	}
	cout<<ans<<endl;
	return 0;
}
