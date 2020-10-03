#include<iostream>
#include<cstdio>
using namespace std;
const int maxn = 1e5+10;
struct Node{
	int x, y, dx, dy;
};
Node nodes[maxn];

int main()
{
	int ans = -1, i, N;
	cin>>N;
	for(i=1;i<=N;i++) {
		scanf("%d %d %d %d", &nodes[i].x, &nodes[i].y, &nodes[i].dx, &nodes[i].dy);
	}
	int X, Y;
	cin>>X>>Y;
	for(i=1;i<=N;i++) {
		if(X>=nodes[i].x && X<=nodes[i].x+nodes[i].dx)
		if(Y>=nodes[i].y && Y<=nodes[i].y+nodes[i].dy) {
			ans = i;
		}
	}
	cout<<ans;
	return 0;
}
