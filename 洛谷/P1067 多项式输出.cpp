#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
int xi[105];

int main()
{
	int N, i;
	cin>>N;
	for(i=N;i>=0;i--) {
		cin>>xi[i];
	}
	bool start = true;
	for(i=N;i>0;i--) {
		if(xi[i]!=0) {
			if(start) {
				if(xi[i]<0) printf("-");
				xi[i] = abs(xi[i]);
				if(xi[i]!=1) printf("%d", xi[i]);
				printf("x");
				if(i!=1) printf("^%d", i);
				start = false;
			}
			else {
				if(xi[i]>0) printf("+");
				else printf("-");
				xi[i] = abs(xi[i]);
				if(xi[i]!=1) printf("%d", xi[i]);
				printf("x");
				if(i!=1) printf("^%d", i);
			}
		}
	}
	if(xi[0] != 0) {
		if(xi[0]>0) printf("+");
		printf("%d", xi[0]);
	}
	return 0;
}
