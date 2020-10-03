#include<iostream>
#define LL long long
#define lowbit(i) (-i&i)
using namespace std;

inline LL count(int num) {  //得到该数二进制下1的个数 
	LL i=1, cnt=0;
	while(i<=num) {
		if(num&i) cnt++;
		i<<=1;
	}
	return cnt;
}

int main()
{
	LL N, K, ans=0;
	cin>>N>>K;
	if(N<=K) {
		cout<<K-N<<endl;
		return 0;
	}
	while(count(N)>K) {
		ans+=lowbit(N);
		N+=lowbit(N);
	}
	cout<<ans<<endl;
	return 0;
}
