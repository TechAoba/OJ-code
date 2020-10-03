#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N, ans;

inline void query() {
	int poi = 2;  //1×ß1²½µ½2 
	ans = 1;
	while(poi!=1) {
		ans++;
		if(poi<=N) poi = poi+poi;
		else poi = (poi-N)*2-1;
	}
}

int main() 
{
	while(scanf("%d", &N) != EOF) {
		if(N==0) {
			printf("0\n");
			continue;
		}
		query();
		printf("%d\n", ans);
	}
	return 0;
}
