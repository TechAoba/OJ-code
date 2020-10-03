#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define Max(a,b) (a>b?a:b)
using namespace std;
const int MAXN = 1000005;
int N, ans[155];
char A[155][75];

struct Aho_Corasick_Automaton{
	int road[MAXN][26], fail[MAXN], val[MAXN], cnt;
	void CLEAR() {
		memset(road, 0, sizeof(road));
		cnt = 0;
		memset(fail, 0, sizeof(fail));
		memset(val, 0, sizeof(val));
	}
	void Insert(char *s, int id) {
		int now = 0, len = strlen(s);
		for(int i=0;i<len;i++) {
			int to = s[i] - 'a';
			if(!road[now][to]) road[now][to] = ++cnt;
			now = road[now][to];
		}
		val[now] = id;
	}
	void Build() {
		queue<int> Q;
		for(int i=0;i<26;i++) {
			if(road[0][i]) fail[road[0][i]] = 0, Q.push(road[0][i]);
		}
		while(!Q.empty()) {
			int u = Q.front(); Q.pop();
			//cout<<u;
			for(int i=0;i<26;i++) {
				if(road[u][i]) fail[road[u][i]] = road[fail[u]][i], Q.push(road[u][i]);
				else road[u][i] = road[fail[u]][i];
			}
		}
	}
	void Query(char *s) {
		int now = 0, len = strlen(s);
		for(int i=0;i<len;i++) {
			now = road[now][s[i]-'a'];
			for(int t=now;t!=0;t=fail[t]) {
				ans[val[t]]++;
			}
		}
	}
}AC; 

char s[MAXN];
int main()
{
	while(scanf("%d", &N)==1 && N>0) {
		memset(ans, 0, sizeof(ans));
		AC.CLEAR();
		int i;
		for(i=1;i<=N;i++) {
			scanf("%s", A[i]);
			AC.Insert(A[i], i);
		}
		AC.Build(); 
		scanf("%s", s);
		AC.Query(s);
		int Tmax = 0;
		for(int i=1;i<=N;i++) Tmax = Max(Tmax, ans[i]);
		printf("%d\n", Tmax);
		for(int i=1;i<=N;i++) if(ans[i]==Tmax) printf("%s\n", A[i]);
	}
	return 0;
 } 
