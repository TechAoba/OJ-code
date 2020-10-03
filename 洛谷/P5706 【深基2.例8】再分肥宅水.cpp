#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

int main()
{
	int i, N;
	double tot;
	cin>>tot>>N;
	printf("%.3lf\n%d\n", tot/N, 2*N);
	return 0;
}
