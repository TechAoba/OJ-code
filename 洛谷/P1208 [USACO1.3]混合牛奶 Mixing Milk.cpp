#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int N, M;
const int maxn = 5010;
struct Milk{
	int price, total;
	bool operator <(const Milk &a)const{
		return price<a.price;
	}
};
Milk milk[maxn];

int main()
{
	cin>>N>>M;
	int i;
	for(i=0;i<M;i++) {
		scanf("%d %d", &milk[i].price, &milk[i].total);
	}
	sort(milk, milk+M);
	int ans = 0, need;
	for(i=0;i<M;i++) {
		if(N>=milk[i].total) {
			need = milk[i].total;
		}
		else {
			need = N;
		}
		N -= need;
		ans += milk[i].price * need;
		if(N<=0) break;
	}
	cout<<ans;
	return 0;
}
