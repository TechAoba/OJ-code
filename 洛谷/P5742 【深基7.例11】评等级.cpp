#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int i, N, id, a, b;
	cin>>N;
	for(i=0;i<N;i++) {
		cin>>id>>a>>b;
		if(a+b>140 && 0.7*a+0.3*b>80) puts("Excellent");
		else puts("Not excellent");
	}
	return 0;
}
