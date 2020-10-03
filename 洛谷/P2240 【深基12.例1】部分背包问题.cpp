#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct Node{
	int zhong, jia;
	double dan;
	bool operator <(const Node &a)const{
		return dan>a.dan;
	}
}node[105];

int main()
{
	int i, N, M;
	double ans = 0.0;
	cin>>N>>M;
	for(i=0;i<N;i++) {
		cin>>node[i].zhong>>node[i].jia;
		node[i].dan = 1.0*node[i].jia/node[i].zhong;
	}
	sort(node, node+N);
	for(i=0;i<N;i++) {
		if(M>=node[i].zhong) {
			M-=node[i].zhong;
			ans += node[i].jia;
		}
		else {
			ans += 1.0*M*node[i].dan;
			break;
		}
	}
	printf("%.2lf\n", ans);
	return 0;
}
