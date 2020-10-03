#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
#define LL long long
using namespace std;
const int MAXN = 1e5+5, MAXM = 2e5+5;
LL INF = 0x7fffffff, dis[MAXN];
int cnt = 0, head[MAXN], N, M, st;
bool vis[MAXN];

inline int read() {
	int f=1, num=0;
	char c = getchar();
	while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
	while(c>='0' && c<='9') {num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	return f*num;
}

struct Edge{
	int next, v, l;
}edge[MAXM];

inline void add(int u, int v, int l) {
	edge[++cnt].l = l;
	edge[cnt].v = v;
	edge[cnt].next = head[u];
	head[u] = cnt;
}

struct Node{  //起点   使用堆优化 
	int pos, dis;
	Node(int pos, int dis):pos(pos),dis(dis){}
	bool operator <(const Node &a)const {
		return a.dis<dis;
	}
};

priority_queue<Node> Q;

void dijkstra() {
	Q.push(Node(st, 0));
	int x, d, i;
	while(!Q.empty()) {
		Node T = Q.top();
		Q.pop();
		x = T.pos, d=T.dis;
		if(vis[x]) continue;
		vis[x] = true;
		for(i=head[x];i!=0;i=edge[i].next) {
			int to = edge[i].v;
			if(dis[x]+edge[i].l<dis[to]) {
				dis[to] = dis[x] + edge[i].l;
				if(!vis[to]) {
					Q.push(Node(to, dis[to]));
				}
			}
		}
	} 
} 

int main()
{
	memset(head, 0, sizeof(head));
	int i, u, v, l;
	N=read(),M=read(),st=read();
	for(i=1;i<=N;i++) dis[i] = INF;
	dis[st] = 0;
	for(i=0;i<M;i++) {
		u=read();v=read();l=read();
		add(u, v, l);
	}
	dijkstra();
	for(i=1;i<=N;i++) printf("%lld ", dis[i]);
	return 0;
 } 
