#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int N, U, D;

int main()
{
	while(scanf("%d %d %d", &N, &U, &D)==3 && N) {
		int ans = 0, poi = 0;
		bool up = 1;
		while(poi < N) {
			ans++;
			if(up) poi += U;
			else poi -= D;
			up = 1 - up;
		}
		printf("%d\n", ans);
	}
	return 0;
}
