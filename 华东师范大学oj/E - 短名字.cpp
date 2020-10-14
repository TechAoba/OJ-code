#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAXN = 8e5;

struct Trie{
	int id, road[MAXN][26], val[MAXN]; 
	bool vis[MAXN];
	int toDi(char c) {return c-'a';}
	Trie() {
		id = 1;
		memset(road[0], 0, sizeof(road[0]));
	}
	void Insert(char *s) {
		bool ok = false;
		int len = strlen(s), now = 0;
		for(int i=0;i<len;i++) {
			int to = toDi(s[i]);
			if(!road[now][to]) { 
				memset(road[id], 0, sizeof(road[id]));
				road[now][to] = id++;
				if(!ok) { 
					for(int j=0;j<=i;j++) printf("%c", s[j]);
					putchar('\n');
					//vis[now] = 1;
					ok = 1;
				}
			}
			now = road[now][to];
		}
		val[now]++;
		if(!ok) {
			if(val[now]>1) {
				printf("%s %d\n", s, val[now]);
			}
			else {
				printf("%s\n", s);
			}
		} 
	} 
}tree;

int main()
{
	int N, i;
	scanf("%d", &N);
	char s[15];
	for(i=0;i<N;i++) {
		scanf("%s", s);
		tree.Insert(s);
	}
	return 0;
}
