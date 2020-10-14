#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int n, m, minlen = 0, ans1 = 0, ans2 = 0, i, j;
	scanf("%d %d", &n, &m);
	minlen = n<m?n:m;
	for(i=1;i<=minlen;i++) {
		ans1 += (n+1-i) * (m+1-i);
	}
	ans2 = ((n+1)*(m+1)*m*n) / 4 - ans1;
	printf("%d %d\n", ans1, ans2);
	return 0;
} 
