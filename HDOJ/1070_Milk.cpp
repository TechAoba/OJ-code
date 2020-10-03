#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 105;
int T, N;
struct Node{
	double dan;
	int volume;
	string name;
	bool operator<(const Node &a)const{
		return dan==a.dan?volume>a.volume:dan<a.dan;
	}
}node[MAXN];

int main()
{
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		int i, total, V, day;
		for(i=0;i<N;i++) {
			cin>>node[i].name;
			scanf("%d %d", &total, &V);
			day = V/200;
			if(day>5) day = 5;
			node[i].volume = V;
			node[i].dan = 1.0*total/day;
		}
		sort(node, node+N);
		cout<<node[0].name<<endl;
	}
	return 0;
} 
