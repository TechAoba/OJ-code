#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
#include<fstream>

using namespace std;
const int MAXM = 400005, MAXN = 100005;
int N, M, dp[MAXN], head[MAXN], ru[MAXN], cnt=0;
struct Edge{
	int to, Next;
}edge[MAXM];

void add(int a, int b) {
	edge[++cnt].to = b;
	edge[cnt].Next = head[a];
	head[a] = cnt;
}

void TP() {
	int Stack[MAXN], top = 0, i, j;
	for(i=1;i<=N;i++) {
		if(!ru[i]) {  //当首节点 
			dp[i] = 1;
			Stack[top++] = i;  //i节点入栈 
			//TPsort[cnt++] = i;
		}
	}
	while(top>0) {
		int u = Stack[--top];
		for(j=head[u];j!=0;j=edge[j].Next) {
			int to = edge[j].to;
			ru[to]--;
			if(!ru[to]) Stack[top++] = to;  //入栈
			dp[to] = Max(dp[to], dp[u]+1);
		}
	}
}

int main()
{
	//ifstream fcin("P1137_5.in",ios::in);
	//ofstream fcout("out.txt",ios::out);
	scanf("%d %d", &N, &M);
	//fcin>>N>>M;
	int i, a, b;
	for(i=1;i<=N;i++) dp[i] = 1;
	for(i=1;i<=M;i++) {
		scanf("%d %d", &a, &b);
		//fcin>>a>>b;
		add(a, b);
		ru[b]++;
	}
	cnt = 0;
	TP();
	for(i=1;i<=N;i++) {
		printf("%d\n", dp[i]);
		//fcout<<dp[i]<<endl;
	}
	//fcin.close();
	//fcout.close();
	//printf("写入成功\n");
	return 0;
}
