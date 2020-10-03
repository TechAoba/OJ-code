#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
const int MAXN = 5e5+5, INF=0x7fffffff; 
int st, N, M, cnt=1;
LL dis[MAXN];  //dis[i]代表起点到达i点的最短距离 
bool vis[MAXN];  //vis[i]代表i节点是否在队列中 
int head[MAXN];   //head[i]代表以i为起点的最后一条边的位置 

struct Edge{
	int l, v, next;  //next[i]代表同样以i为起点的上一条边的位置 
}edge[MAXN];

void add(int u, int v, int l) {  //链式前向星建图 
	edge[cnt].l=l;
	edge[cnt].v=v;
	edge[cnt].next = head[u];
	head[u] = cnt++;
}

void spfa() {
	int i, u, to;
	queue<int> Q;
	Q.push(st), vis[st] = true;
	while(!Q.empty()) {
		u=Q.front(), Q.pop(), vis[u]=false;
		for(i=head[u];i!=0;i=edge[i].next) {
			//cout<<1;
			to = edge[i].v;
			if(dis[u]+edge[i].l<dis[to]) {
				dis[to] = dis[u]+edge[i].l;
				if(!vis[to]) {
					vis[to] = true;
					Q.push(to);
				}
			}
		}
	}
}

int main()
{
	memset(head, 0, sizeof(head));
	int i, u, v, l;
	cin>>N>>M>>st;
	for(i=1;i<=N;i++) dis[i] = INF;
	dis[st] = 0;
	for(i=0;i<M;i++) {
		scanf("%d%d%d", &u, &v, &l);
		add(u, v, l);
	}
	spfa();
	for(i=1;i<=N;i++) printf("%lld%c", dis[i], i==N?'\n':' ');
	return 0;
}
