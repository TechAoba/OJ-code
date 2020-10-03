#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1005;

struct people{
	int id;
	double tim;
	bool operator <(const people &a)const{
		return tim<a.tim;
	}
};
people peo[maxn];
int N;

int main()
{
	cin>>N;
	int i;
	for(i=1;i<=N;i++) {
		cin>>peo[i].tim;
		peo[i].id = i;
	}
	sort(peo+1, peo+1+N);
	double ans = 0;
	for(i=1;i<=N;i++) {
		printf("%d%c", peo[i].id, i==N?'\n':' ');
		ans += peo[i].tim*(N-i);
		//cout<<"µÈ´ý"<<peo[i].tim<<" * "<<(N-i+1)<<endl;
	}
	printf("%.2lf", ans/N);
	return 0;
}
