#include<iostream>
#include<cstdio>
#include<cstring>
#define res register int
using namespace std;
const int MAXN = 500010;
int N, M;

struct Trie{
	int id, road[MAXN][26], val[MAXN];
	Trie() {  //初始化 
		memset(road[0], 0, sizeof(road[0]));
		memset(val, 0, sizeof(val));
		id = 1;
	}
	int toDi(char c) {return c-'a';}
	void Insert(char *s) {
		int len = strlen(s);
		int now = 0;
		for(int i=0;i<len;i++) {
			int to = toDi(s[i]);
			if(!road[now][to]) {  //新建节点 
				memset(road[id], 0, sizeof(road[id]));
				road[now][to] = id++;
			}
			now = road[now][to];
		}
	}
	int search(char *s) {  //0表示未找到  1表示正确  2表示找过了 
		int len = strlen(s);
		int now = 0;
		for(int i=0;i<len;i++) {
			int to = toDi(s[i]);
			if(!road[now][to]) return 0;
			now = road[now][to];
		}
		if(val[now]==1) return 2;
		val[now] = 1;
		return 1;
	}
}tree;

int main()
{
	scanf("%d", &N);
	res i;
	char s[55];
	for(i=0;i<N;i++) {
		scanf("%s", s);
		tree.Insert(s);
	}
	scanf("%d", &M);
	for(i=0;i<M;i++) {
		scanf("%s", s);
		int ans = tree.search(s);
		if(ans==0) printf("WRONG\n");
		else if(ans==1) printf("OK\n");
		else if(ans==2) printf("REPEAT\n");
	}
	return 0;
}
