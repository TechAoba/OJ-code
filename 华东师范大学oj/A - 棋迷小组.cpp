#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;

int main()
{
	LL a, b, c, ans=0;
	cin>>a>>b>>c;
	ans = Min(a,b);
	a-=ans, b-=ans;
	a+=b;
	if(a>=c) ans+=c;
	else {
		ans+=a;
		c-=a;
		ans += c/2;
	}
	printf("%lld\n", ans*2);
	return 0;
} 
