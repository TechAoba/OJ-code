#include<cstdio>
#include<iostream>
#define LL long long 
using namespace std;
int T;
double A, B, H;

int main()
{
	while(scanf("%d", &T) != EOF) {
		while(T--) {
			cin>>A>>B>>H;
			printf("%.2lf\n", B*H/A);
		}
	}
	return 0;
}
