#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL N, M, now = 0;

int main()
{
	cin>>N>>M;
	int a, ans = 1;
	for(int i=0;i<N;i++) {
		scanf("%d", &a);
		now += a;
		if(now>M) {
			now = a;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
