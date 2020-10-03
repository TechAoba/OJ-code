#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 5e5;
char TZ[1005][55];
int N, num[1005];

struct Aho_Corasick_Automaton{
	int road[MAXN][128], fail[MAXN], val[MAXN], cnt;
	void Init() {
		cnt = 0;
		memset(road[0], 0, sizeof(road[0]));
		memset(fail, 0, sizeof(fail));
		memset(val, 0, sizeof(val));
	}
	void Insert(char *s, int id) {
		int now=0,len=strlen(s);
		for(int i=0;i<len;i++) {
			int to = (int)s[i];
			if(!road[now][to]) {  //新建节点 
				++cnt;
				memset(road[cnt], 0, sizeof(road[cnt]));
				road[now][to] = cnt;
			}
			now = road[now][to];
		}
		val[now] = id;
	}
	void Build() {
		queue<int> Q;
		for(int i=0;i<128;i++) {
			if(road[0][i]) fail[road[0][i]] = 0, Q.push(road[0][i]);
		}
		while(!Q.empty()) {
			int u = Q.front(); Q.pop();
			for(int i=0;i<128;i++) {
				if(road[u][i]) fail[road[u][i]] = road[fail[u]][i], Q.push(road[u][i]);
				else road[u][i] = road[fail[u]][i];
			}
		}
	}
	void Query(char *s) {
		int i, len = strlen(s), now = 0;
		for(i=0;i<len;i++) {
			now = road[now][s[i]];
			for(int t = now;t!=0;t=fail[t]) {
				num[val[t]]++;
			}
		}
		for(i=1;i<=N;i++) if(num[i]) {
			printf("%s: %d\n", TZ[i], num[i]);
		}
	}
}AC;

char s[2000000+5];
int main()
{
	while(scanf("%d", &N) != EOF) {
		int i;
		AC.Init();
		memset(num, 0, sizeof(num));
		for(i=1;i<=N;i++) {
			scanf("%s", TZ[i]);
			AC.Insert(TZ[i], i);
		}
		AC.Build();
		scanf("%s", s);
		AC.Query(s);
	}
	return 0;
}
