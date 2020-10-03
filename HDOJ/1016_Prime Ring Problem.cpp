#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN = 50;
bool prime[MAXN], vis[MAXN];
int pp[MAXN], N, cnt=0, head[MAXN], A[MAXN];
vector<int> V[MAXN];

/*struct Edge{
	int to, Next;
}edge[300];

void add(int a, int b) {
	edge[++cnt].to = b;
	edge[cnt].Next = head[a];
	head[a] = cnt;
}*/

void getPrime() {
	for(int i=2;i<MAXN;i++) {
		if(!vis[i]) prime[i] = true, pp[cnt++] = i;
		for(int j=0;j<cnt && i*pp[j]<MAXN;j++) {
			vis[i*pp[j]] = true;
			if(i%pp[j]==0) break;
		}
	}
}

void print() {
	for(int i=1;i<=N;i++) printf("%d%c", A[i], i==N?'\n':' ');
}

void dfs(int now) {
	if(now==N-1) {
		for(int i=0;i<V[A[now]].size();i++) {
			int to = V[A[now]][i];
			//if(A[now]==7) cout<<"找到了"<<to<<endl;
			if(!vis[to] && prime[to+1]) {
				A[N] = to;
				print();
				return;  //找到输出 
			}
		}
		return;  //不符合条件返回 
	}
	for(int i=0;i<V[A[now]].size();i++) {
		int to = V[A[now]][i];
		if(!vis[to]) {
			vis[to] = 1;
			A[now+1] = to;
			dfs(now+1);
			vis[to] = 0;
		}
	}
}

int main()
{
	getPrime();
	int kase=1, i, j;
	while(scanf("%d", &N)!=EOF) {
		for(i=1;i<=N;i++) V[i].clear();
		cnt = 0;
		memset(vis, 0, sizeof(vis));
		for(i=1;i<=N;i++) {
			for(j=1;j<=N;j++) {
				if(i!=j && prime[i+j]) V[i].push_back(j);
			}
		}
		A[1] = 1;
		vis[1] = 1;
		printf("Case %d:\n", kase++);
		dfs(1);
		putchar('\n');
	}
	return 0;
 } 
