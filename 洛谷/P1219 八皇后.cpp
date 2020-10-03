#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int A[20], N, ans = 0;
bool vis[20], vis1[20], vis2[20];
void print() {
	for(int i=1;i<=N;i++) {
		printf("%d%c", A[i], i==N?'\n':' ');
	}
}

void dfs(int step) {
	if(step>N) {
		ans++;
		if(ans<=3) print();
		return;
	}
	for(int i=1;i<=N;i++) {
		if(vis[i] || vis1[i+step] || vis2[N+i-step]) continue;
		A[step] = i;
		vis[i] = true;
		vis1[i+step] = true;
		vis2[N+i-step] = true;
		dfs(step+1);
		vis2[N+i-step] = false;
		vis1[i+step] = false;
		vis[i] = false;
	}
}

int main()
{
	memset(A, 0, sizeof(A));
	cin>>N;
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
