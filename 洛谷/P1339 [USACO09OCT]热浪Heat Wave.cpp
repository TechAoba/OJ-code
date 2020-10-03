#include<iostream>
#include<queue>
#include<cstdio>
using namespace std;
struct Node{
	int to, dis;
	bool operator<(const Node &a)const{
		return a.dis<dis;
	}
	Node(int to, int dis):to(to),dis(dis){}
	Node():to(0),dis(0){}
};
priority_queue<Node> Q;
struct Edge{
	int to, len, next;
}edge[12405];
int head[12405], cnt=0, N, M, st, en, dis[2505];
const int INF = 0x3f3f3f3f;
bool vis[2505];
void add(int a, int b, int w) {
	edge[++cnt].len = w;
	edge[cnt].to = b;
	edge[cnt].next = head[a];
	head[a] = cnt;
}

int main()
{
	scanf("%d %d %d %d", &N, &M, &st, &en);
	int i, u, v, w;
	for(i=1;i<=N;i++) {
		dis[i] = INF;
	}
	dis[st] = 0;
	for(i=0;i<M;i++) {
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w), add(v, u, w);
	}
	Q.push(Node(st, 0));
	while(!Q.empty()) {
		Node T = Q.top(); Q.pop();
		int u = T.to, dis1 = T.dis;
		if(u==en) {
			cout<<dis1<<endl;
			return 0;
		}
		if(vis[u]) continue;
		vis[u] = true;
		for(i=head[u];i!=0;i=edge[i].next) {
			int to = edge[i].to;
			if(dis1+edge[i].len<dis[to]) {
				dis[to] = dis1+edge[i].len;
				if(!vis[to]) Q.push(Node(to, dis[to]));
			}
		}
	}
	return 0;
}
