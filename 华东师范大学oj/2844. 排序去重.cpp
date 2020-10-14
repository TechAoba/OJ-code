#include<iostream>
#include<cstdio>
using namespace std;
char op[3];
bool vis[1005];

int main()
{
	scanf("%s", op);
	int a, i;
	bool flag=0;
	while(scanf("%d", &a)!=EOF) {
		vis[a] = 1;
	}
	if(op[0]=='A') {
		for(i=0;i<=1000;i++) {
			if(vis[i]) {
				if(flag) putchar(' ');
				flag=1;
				printf("%d", i);
			}
		}
	}
	else {
		for(i=1000;i>=0;i--) {
			if(vis[i]) {
				if(flag) putchar(' ');
				flag=1;
				printf("%d", i);
			}
		}
	}
	return 0;
}
