#include<iostream>
#include<cstdio>
#include<cstring>
#define Max(a,b) (a>b?a:b)
using namespace std;

void fun(int n) {
	if(n>=5) {
		n-=5;
		printf("-O|");
	}
	else {
		printf("O-|");
	}
	if(n==0) {
		printf("-OOOO\n");
	}
	else if(n==1) {
		printf("O-OOO\n");
	}
	else if(n==2) {
		printf("OO-OO\n");
	}
	else if(n==3) {
		printf("OOO-O\n");
	}
	else if(n==4) {
		printf("OOOO-\n");
	}
}

void dfs(int n) {
	while(n) {
		fun(n%10);
		n/=10;
	}
}

int main()
{
	int N;
	cin>>N;
	if(N==0) {
		printf("O-|-OOOO\n");
	}
	else dfs(N);
	return 0;
}
