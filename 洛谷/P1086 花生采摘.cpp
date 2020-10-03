#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int cnt = 0, R, C, K;
struct Node{
	int r, c, num;
	bool operator<(const Node &a)const {
		return num>a.num;
	}
}node[405];

int main()
{
	int r, c, a, i;
	cin>>R>>C>>K;
	for(r=1;r<=R;r++) {
		for(c=1;c<=C;c++) {
			cin>>a;
			if(a!=0) {
				node[cnt].r = r;
				node[cnt].c = c;
				node[cnt++].num = a;
			}
		}
	}
	sort(node, node+cnt);
	//cout<<node[0].num<<endl<<node[1].num<<endl<<node[2].num<<endl;
	if(node[0].r*2+1>K) {  //第一个点都拿不到 
		cout<<0<<endl;
		return 0;
	}
	int ans = node[0].num, step = node[0].r+1;
	for(i=1;i<cnt;i++) {
		int T = abs(node[i].r-node[i-1].r)+abs(node[i-1].c-node[i].c)+1;
		if(step+T+node[i].r<=K) {
			ans += node[i].num;
			step += T;
		}
		else break;
	}
	cout<<ans<<endl;
	return 0;
}
