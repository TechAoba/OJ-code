#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N, M, ans[30];

void dfs(int left, int now) {
	int i;
	if(!left) {
		for(i=1;i<=M;i++) {
			printf("%3d", ans[i]);
		}
		putchar('\n');
		return;
	}
	if(N-now+1<left) return;
	for(i=now;i<=N;i++) {
		ans[M-left+1] = i;
		dfs(left-1, i+1);
	}
}

int main()
{
	scanf("%d %d", &N, &M);
	dfs(M, 1);
	return 0;
}
