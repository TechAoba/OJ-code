#include<iostream>
#include<cstdio>
#define res register int
using namespace std;
const int MAXN = 1e6+10;
int Fb[MAXN];

int main()
{
	Fb[0] = 1, Fb[1] = 2;
	res i;
	for(i=2;i<MAXN;i++) {
		Fb[i] = (Fb[i-1] + Fb[i-2]) % 3;
	}
	int query;
	while(scanf("%d", &query) != EOF) {
		if(!Fb[query]) printf("yes\n");
		else printf("no\n"); 
	} 
	return 0;
}
