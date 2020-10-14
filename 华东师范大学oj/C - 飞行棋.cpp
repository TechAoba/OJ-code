#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;
bool vis[10005];
struct Node{
	int step, id;
	Node(int id, int step):id(id),step(step){}
};
int R, C, T, Y, target, Next[10005];

int main()
{
	int i, a, b;
	while(scanf("%d %d %d %d", &R, &C, &T, &Y) != EOF) {
		memset(vis, 0, sizeof(vis));
		memset(Next, -1, sizeof(Next));
		for(i=1;i<=T+Y;i++) {
			scanf("%d %d", &a, &b);
			Next[a] = b;
		}
		target = R*C;
		if(Next[target] != -1) {
			printf("-1\n");
			continue;
		}
		queue<Node> Q;
		vis[0] = 1;
		Q.push(Node(0, 0));
		bool ok = 0;
		while(!Q.empty()) {
			Node T = Q.front(); Q.pop();
			int step = T.step, id = T.id;
			for(i=1;i<=6;i++) {
				int nid = id+i;
				if(nid==target) {
					printf("%d\n", step+1);
					ok = 1;
					break;
				}
				while(Next[nid]!=-1) nid = Next[nid];
				if(!vis[nid]) {
					vis[nid]=1;
					Q.push(Node(nid, step+1));
					//printf("·ÃÎÊµ½ÁË%d\n", nid);
				}
			}
			if(ok) break;
		}
		if(!ok) printf("-1\n");
	}
	return 0;
}
