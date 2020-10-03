#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 6e5;
queue<int> Q;

struct Aho_Corasick_Automaton{
	int road[MAXN][26], cnt, val[MAXN], fail[MAXN];
	Aho_Corasick_Automaton() {
		cnt = 0;
		memset(val, 0, sizeof(val));
		memset(fail, 0, sizeof(fail));
	}
	void Insert(char *s) {
		int len = strlen(s);
		int now = 0;
		for(int i=0;i<len;i++) {
			int to = s[i] - 'a';
			if(!road[now][to]) {  //�½��ڵ� 
				road[now][to] = ++cnt;
			}
			now = road[now][to];
		}
		val[now]++;  //����������һ 
	}
	void Build() {  //����fail�� 
		for(int i=0;i<26;i++) {  //�Ӹ��ڵ� 
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
		int ans = 0, len = strlen(s), now = 0;
		for(int i=0;i<len;i++) {
			now = road[now][s[i]-'a'];
			for(int t = now;t&&val[t] != -1;t=fail[t]) ans += val[t], val[t] = -1;
		}
		return ans;
	}
}AC;

char S[1000005];
int main()
{
	int N;
	scanf("%d", &N);
	for(int i=0;i<N;i++) {
		scanf("%s", S);
		AC.Insert(S);
	}
	AC.Build();
	scanf("%s", S);
	printf("%d\n", AC.Query(S));
	return 0;
}
