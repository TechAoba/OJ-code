#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
using namespace std;
const int MAXN = 105;
char A[MAXN][MAXN];
bool vis[MAXN][MAXN];
int R, C, K, sum[256];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

struct Node{
	char c;
	int num;
	bool operator <(const Node &a)const{
		return num==a.num?c<a.c:num>a.num;
	}
};

vector<Node> V;

void dfs(int r, int c, char ch) {
	if(vis[r][c] || A[r][c]!=ch) return;
	vis[r][c] = 1;
	for(int i=0;i<4;i++) {
		int nr=r+dr[i], nc = c+dc[i];
		if(nr>R||nc>C||nr<1||nc<1) continue;
		dfs(nr, nc, ch);
	}
}

int main()
{
	K = read();
	int r, c, i;
	for(int kase=1;kase<=K;kase++) {
		memset(vis, 0, sizeof(vis));
		memset(sum, 0, sizeof(sum));
		Node node[256];
		R = read(), C = read();
		for(r=1;r<=R;r++) {
			scanf("%s", A[r]+1);
		}
		for(r=1;r<=R;r++) {
			for(c=1;c<=C;c++) {
				if(!vis[r][c]) {
					sum[A[r][c]]++;
					dfs(r, c, A[r][c]);
				}
			}
		}
		int cnt=0;
		for(i=1;i<256;i++) {
			if(sum[i]) {
				node[cnt].c = i;
				node[cnt++].num = sum[i];
			}
		}
		sort(node, node+cnt);
		printf("World #%d\n", kase);
		for(i=0;i<cnt;i++) {
			printf("%c: %d\n", node[i].c, node[i].num);
		}
	}
	return 0;
 } 
