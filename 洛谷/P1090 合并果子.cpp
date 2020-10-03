#include<iostream>
#include<cstdio>
#include<queue>
#define LL long long
using namespace std;
priority_queue<int,vector<int>,greater<int> > Q;

int main()
{
	int N, i, val;
	LL ans = 0;
	scanf("%d", &N);
	for(i=0;i<N;i++) {
		scanf("%d", &val);
		Q.push(val);
	}
	while(Q.size()>=2) {
		int a = Q.top(); Q.pop();
		int b = Q.top(); Q.pop();
		ans += a+b;
		Q.push(a+b);
	}
	cout<<ans;
	return 0;
}
