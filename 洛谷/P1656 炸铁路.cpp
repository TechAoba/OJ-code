#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
using namespace std;
int N, M, cnt=0, head[155], dfn[155], low[155], timeVal=0, len=0;
struct Edge{
	int to, Next;
}edge[5005];
struct Ans{
	int a, b;
	bool operator<(const Ans &t)const{
		return a==t.a?b<t.b:a<t.a;
	}
}ans[5005];

void add(int a, int b) {
	edge[++cnt].to = b;
	edge[cnt].Next = head[a];
	head[a] = cnt;
}

void tarjan(int now, int fa) {
	dfn[now] = low[now] = ++timeVal;  //给予时间戳 
	for(int i=head[now];i!=0;i=edge[i].Next) {
		int to = edge[i].to;
		if(dfn[to] && to!=fa) {  //下一个节点为不是父节点的已访问点 
			low[now] = Min(low[now], dfn[to]);
		}
		else if(!dfn[to]) {
			tarjan(to, now);
			low[now] = Min(low[now], low[to]);
			if(low[to] > dfn[now]) {  //是割边 
				ans[len].a = Min(now, to);
				ans[len++].b = Max(now, to);
			}
		}
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	int i, a, b;
	for(i=1;i<=M;i++) {
		scanf("%d %d", &a, &b);
		add(a, b), add(b, a);
	}
	tarjan(1, 1);
	sort(ans, ans+len);
	for(i=0;i<len;i++) {
		printf("%d %d\n", ans[i].a, ans[i].b);
	}
	return 0;
}
