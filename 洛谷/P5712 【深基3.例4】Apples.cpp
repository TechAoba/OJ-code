#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
	int N;
	cin>>N;
	if(N>1) printf("Today, I ate %d apples.\n", N);
	else printf("Today, I ate %d apple.\n", N);
	return 0;
}
