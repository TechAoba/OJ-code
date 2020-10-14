#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int MAXN = 1e6+10;
bool marked[MAXN];

struct Trie{
	int id, road[MAXN][26];
	bool end[MAXN];
	Trie() {id=1;memset(road[0], 0, sizeof(road));}
	void Insert(char *s) {
		int len = strlen(s), now=0;
		for(int i=0;i<len;i++) {
			int to = s[i]-'a';
			if(!road[now][to]) {  //新建节点 
				road[now][to] = id++;
			}
			now = road[now][to];
		}
		end[now] = 1;//以now结尾 
	}
	void Search(char *s) {
		memset(marked, 0, sizeof(marked));
		int ans=0, len = strlen(s), now=0, i, j;
		for(i=0;i<len;i++) {
			int to = s[i]-'a';
			now = road[now][to];
			if(now==0) break;
			if(end[now]) marked[i] = 1;
		}
		for(i=0;i<len;i++) {
			if(!marked[i]) continue;
			ans = i+1;
			now = 0;
			for(j=i+1;j<len;j++) {
				int to = s[j]-'a';
				now = road[now][to];
				if(now==0) break;
				if(end[now]) marked[j] = 1;
			}
		}
		printf("%d\n", ans);
	}
}tree;

int main()
{
	int N, M, i;
	char s[MAXN];
	scanf("%d %d", &N, &M);
	for(i=0;i<N;i++) {
		scanf("%s", s);
		tree.Insert(s);
	}
	for(i=0;i<M;i++) {
		scanf("%s", s);
		tree.Search(s);
	}
	return 0;
 } 
