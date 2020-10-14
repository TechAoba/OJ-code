#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int a;    		// 上车人数a
	int n;			// 车站数n
	int m;			// 终点站下车人数m
	int x;			// 所求站点x
	scanf("%d %d %d %d", &a, &n, &m, &x);
	int x1[30], x2[30];  	// 系数 x1*a + x2*b = m
	x1[1] = x1[2] = 1;
	x2[1] = x2[2] = x2[3] = 0;
	x1[3] = 2, x1[4] = 2;
	x2[4] = 1;
	for(int i=5;i<25;i++) {
		x1[i] = x1[i-2] + x1[i-1] - 1;
		x2[i] = x2[i-2] + x2[i-1] + 1;
	}
	int b = (m - a*x1[n-1]) / x2[n-1];
	int ans = x1[x]*a + x2[x]*b;
	printf("%d\n", ans);
	return 0;
}
