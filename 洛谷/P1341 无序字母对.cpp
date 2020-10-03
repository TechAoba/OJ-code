#include<iostream>
#include<cstdio>
#define res register int
using namespace std;
const int MAXN = 257; 
bool vis[MAXN][MAXN];
int parent[MAXN], deep[MAXN], N;
char ans[MAXN*MAXN];

inline int find(int a) {
	if(parent[a]!=a) parent[a] = find(parent[a]);
	return parent[a];
}

void dfs(int st) {
	int i;
	for(i=1;i<MAXN;i++) {
		if(vis[st][i]) {
			vis[st][i]=vis[i][st]=false;
			dfs(i);
		}
	}
	ans[N--] = st;
}

int main()
{
	int i, a, b;
	for(i=1;i<MAXN;i++) parent[i]=i;
	char A[MAXN];
	cin>>N;
	for(i=0;i<N;i++) {
		scanf("%s", A);
		a = A[0], b = A[1];
		vis[a][b] = vis[b][a] = true;
		deep[a]++, deep[b]++;  //�ȼ�1 
		res pa = find(a), pb = find(b);
		parent[pa] = pb;  //�ϲ� 
	}
	int cnt = 0, st=0, num=0;  //cnt�Ƕ�Ϊ�����ĵ� num������ͼ���� 
	for(i=1;i<MAXN;i++) {
		if(deep[i]&1) {
			cnt++;
			if(!st) st=i;  //stΪ��� 
		}
		if(deep[i] && parent[i]==i) num++;
	}
	if(cnt && cnt!=2 || num!=1) {  //������ŷ��·�� ���� ����ͨ 
		puts("No Solution");
		return 0;
	}
	if(!st) {
		for(i=1;i<MAXN;i++) {
			if(deep[i]) {
				st = i;
				break;
			}
		}
	}
	dfs(st);
	puts(ans);
	return 0;
}
