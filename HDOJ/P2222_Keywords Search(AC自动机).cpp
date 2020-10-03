#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 8e5;
int T, N;

struct Aho_Corasick_Automaton{
	int road[MAXN][26], id, fail[MAXN], val[MAXN];
	void Init() {  //初始化 
		id = 0;
		memset(road[0], 0, sizeof(road[0]));
		memset(val, 0, sizeof(val));
		memset(fail, 0, sizeof(fail));
	}
	void Insert(char *s) {
		int len = strlen(s), now = 0;
		for(int i=0;i<len;i++) {
			int to = s[i] - 'a';
			if(!road[now][to]) {  //新建节点 
				id++;
				memset(road[id], 0, sizeof(road[id]));
				road[now][to] = id;
			}
			now = road[now][to];
		}
		val[now]++;
	}
	void Build() {
		queue<int> Q;
		for(int i=0;i<26;i++) {
			if(road[0][i]) fail[road[0][i]] = 0, Q.push(road[0][i]);
		}
		while(!Q.empty()) {
			int u = Q.front(); Q.pop();
			for(int i=0;i<26;i++) {
				if(road[u][i]) fail[road[u][i]] = road[fail[u]][i], Q.push(road[u][i]);
				else road[u][i] = road[fail[u]][i];
			}
		}
	}
	int Query(char *s) {
		int now=0, len=strlen(s), ans=0;
		for(int i=0;i<len;i++) {
			now = road[now][s[i]-'a'];
			for(int t=now;t && val[t]!=-1;t=fail[t]) {
				ans += val[t];
				val[t] = -1;
			}
		}
		return ans;
	}
}AC;

char s[1000000+5];
int main()
{
	scanf("%d", &T);
	while(T--) {
		AC.Init();
		int i;
		scanf("%d", &N);
		for(i=0;i<N;i++) {
			scanf("%s", s);
			AC.Insert(s);
		}
		AC.Build();
		scanf("%s", s);
		printf("%d\n", AC.Query(s));
	}
	return 0;
}
