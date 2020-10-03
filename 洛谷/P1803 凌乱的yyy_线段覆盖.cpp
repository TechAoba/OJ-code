#include<iostream>
#include<algorithm>
#include<cstdio>
#define res register int
using namespace std;
const int MAXN = 1000005; 
struct Node{
	int st, en;
	bool operator<(const Node &a)const{
		return en<a.en;
	}
}node[MAXN];
int N;

int main()
{
	scanf("%d", &N);
	res i;
	for(i=0;i<N;i++) scanf("%d %d", &node[i].st, &node[i].en);
	sort(node, node+N);
	int ans = 1, last=node[0].en;
	for(i=2;i<N;i++) {
		if(node[i].st>=last) {
			last = node[i].en;
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
