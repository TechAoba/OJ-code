#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
LL N, a, add, ans;

inline LL read() {
	LL num = 0;
	char c = getchar();
	while(c<'0' || c>'9') c=getchar();
	while(c>='0' && c<='9') num = (num<<3)+(num<<1)+(c^48), c=getchar();
	return num;
}

inline LL getnum(LL b) {  //出现的次数 
	ans=0;
	while(b<=N) {
		add = (-b&b); 
		ans += add;
		if(b+add>N) {
			ans -= (b+add-N-1);
		}
		b<<=1;
		//cout<<b<<endl;
	}
	return ans;
}

LL midFind(LL low, LL high) {
	LL mid;
	while(low<high) {
		mid = (low+high)/2;
		//cout<<mid<<endl;
		if(getnum(mid)>a) {   //小了 
			low=mid+1;
		}
		else high=mid-1;
	}
	if(mid>1) mid--;
	while(getnum(mid)>=a) mid++;
	return --mid;
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) {
		N=read(), a=read();
		if(a==1) {
			printf("%lld\n", N);
			continue;
		}
		printf("%lld\n", midFind(1, N));
	}
	return 0;
}
