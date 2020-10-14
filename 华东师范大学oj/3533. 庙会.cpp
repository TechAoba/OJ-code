#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int m, n, k, i=1, j=1;
	cin>>m>>n>>k;
	while(k--) {
		printf("%d %d\n", i, j);
		i++, j++;
		if(i>m) i = 1;
		if(j>n) j = 1;
	}
	return 0;
}
