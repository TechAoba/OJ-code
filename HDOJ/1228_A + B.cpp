#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char num[10][10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};

int main()
{
	char s[20];
	while(1) {
		int a = 0, b = 0, t, i;
		while(scanf("%s", s)) {
			if(strcmp("+", s) == 0) break;
			for(i=0;i<10;i++) {
				if(strcmp(num[i], s) == 0) break;
			}
			a = a*10+i;
		}
		
		while(scanf("%s", s)) {
			if(strcmp("=", s) == 0) break;
			for(i=0;i<10;i++) {
				if(strcmp(num[i], s) == 0) break;
			}
			b = b*10+i;
		}
		if(a==0 && b==0) break;
		printf("%d\n", a+b);
	}
	return 0;
}
