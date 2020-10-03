#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#define LL long long
using namespace std;
const int MAXN = 5e5+5, INF=0x7fffffff; 
int st, N, M, cnt=1;
LL dis[MAXN];  //dis[i]������㵽��i�����̾��� 
bool vis[MAXN];  //vis[i]����i�ڵ��Ƿ��ڶ����� 
int head[MAXN];   //head[i]������iΪ�������һ���ߵ�λ�� 

struct Edge{
	int l, v, next;  //next[i]����ͬ����iΪ������һ���ߵ�λ�� 
}edge[MAXN];

void add(int u, int v, int l) {  //��ʽǰ���ǽ�ͼ 
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
