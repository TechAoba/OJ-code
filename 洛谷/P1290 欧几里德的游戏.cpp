#include<iostream>
#include<cstdio>
using namespace std;

int dfs(int a, int b, int who) {
	if(a==b || b/a>=2) return who;
	return dfs(b-a, a, who^1);
}

int main()
{
	int i, N, a, b;
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>a>>b;
		if(a>b) swap(a, b);
		if(dfs(a, b, 0) == 0) printf("Stan wins\n");
		else printf("Ollie wins\n");
	}
	return 0;
}
