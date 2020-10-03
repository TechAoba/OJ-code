#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int MAXN = 1000005;
int N, M, K;

struct Node{
	double sum;
	int id;
	bool operator <(const Node &a)const{
		return sum==a.sum?id<a.id:sum>a.sum;
	}
}node[MAXN];

bool cmp(int a, int b) {
	return a>b;
}

int main()
{
	int i, j, k;
	double t;
	while(scanf("%d %d %d", &N, &M, &K) != EOF) {
		for(i=1;i<=M;i++) { //³õÊ¼»¯ 
			node[i].id = i;
			node[i].sum = 0;
		}
		for(i=1;i<=N;i++) {
			for(j=1;j<=M;j++) {
				scanf("%lf", &t);
				node[j].sum += t;
			}
		}
		sort(node+1, node+1+M);
		vector<int> V;
		for(i=1;i<=K;i++) V.push_back(node[i].id);
		sort(V.begin(), V.end(), cmp);
		for(i=0;i<V.size();i++)printf("%d%c", V[i], i==V.size()-1?'\n':' ');
	}
	return 0;
}
