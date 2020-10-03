#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
char A[100], B[100];
const int MAXN = 2e5;
int CNT = 0;

struct Aho_Corasick_Automaton{
	int road[MAXN][130], val[MAXN], temp[MAXN], fail[MAXN], ans[MAXN], cnt, num;
	Aho_Corasick_Automaton() {
		cnt = 0;
		memset(val, 0, sizeof(val));
		memset(fail, 0, sizeof(fail));
	}
	void Insert(char *s, int id) {
		int len = strlen(s), now = 0;
		for(int i=0;i<len;i++) {
			int to = (int)s[i];
			if(!road[now][to]) {  //新建节点 
				road[now][to] = ++cnt;
			}
			now = road[now][to];
		}
		val[now] = id;
	}
	void Build() {  //构建fail树 
		queue<int> Q;
		for(int i=0;i<130;i++) {
			if(road[0][i]) fail[road[0][i]] = 0, Q.push(road[0][i]);
		}
		while(!Q.empty()) {
			int u = Q.front(); Q.pop();
			for(int i=0;i<130;i++) {
				if(road[u][i]) fail[road[u][i]] = road[fail[u]][i], Q.push(road[u][i]);
				else road[u][i] = road[fail[u]][i];
			}
		}
	}
	void Query(char *s, int id) {
		int i, now=0, num=0, len = strlen(s);
		for(i=1;i<=cnt;i++) temp[i] = val[i];
		for(i=0;i<len;i++) {
			now = road[now][s[i]];
			for(int t = now;t && temp[t]!=-1;t=fail[t]) {
				if(temp[t]) ans[num++] = temp[t];
				temp[t] = -1;
			}
		}
		if(num>0) {
			CNT++;
			printf("web %d:", id);
			sort(ans, ans+num);
			for(i=0;i<num;i++) printf(" %d", ans[i]);
			putchar('\n');
		}
	}
}AC;

char s[10005];
int main()
{
	int N, i;
	scanf("%d\n", &N);
	for(i=1;i<=N;i++) {
		scanf("%[^\n]", s);
		AC.Insert(s, i);
		getchar();
	}
	AC.Build();
	scanf("%d\n", &N);
	for(i=1;i<=N;i++) {
		scanf("%[^\n]", s);
		getchar(); 
		AC.Query(s, i);
	}
	printf("total: %d\n", CNT);
	return 0;
} 
