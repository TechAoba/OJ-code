#include<iostream>
#include<cmath>
#define LL long long
using namespace std;
LL x, y;
int ans = 0;
LL gcd(LL a, LL b) {
	return a%b==0?b:gcd(b, a%b);
}

int main()
{
	cin>>x>>y;
	LL mul = x*y;
	LL li = (LL)(sqrt(mul) + 0.5);
	for(LL i=2;i<=li;i++) {
		if(!(mul % i)) {
			//cout<<i<<endl;
			if(x == gcd(i, mul/i)) ans++;
		}
	}
	cout<<ans*2;
	return 0;
}
