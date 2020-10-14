#include<iostream>
#include<cstdio>
#include<cstring>
#define LL long long
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;

inline LL read() {
	LL x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

int main()
{
	LL A, B, C, X, Y, ans=0;
	A = read(), B=read(), C = read(), X=read(), Y = read();
	if(C*2<=A+B) {
		LL t = Min(X, Y);
		//cout<<"t=  "<<t<<endl;
		ans += t*2*C;
		X-=t, Y-=t;
		//cout<<"X=  "<<X<<"Y=  "<<Y<<endl;
		if(X==0 && C*2<B) ans+=2*C*Y;
		else if(Y==0 && C*2<A) ans+=2*C*X;
		else ans += X*A + Y*B;
	}
	else {
		ans = X*A+Y*B;
	}
	printf("%lld\n", ans);
	return 0;
 } 
