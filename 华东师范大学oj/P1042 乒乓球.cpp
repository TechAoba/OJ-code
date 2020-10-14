#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
char A[62505];

int main()
{
	int len = 0, w=0, l=0, i;
	while(scanf("%s", A+len)==1) {
		len = strlen(A);
	}
	for(i=0;i<len;i++) {
		if(A[i]=='E') {
			len = i;
			break;
		}
	}
	for(i=0;i<len;i++) {
		if(A[i]=='W') w++;
		else l++;
		if((w>=11 || l>=11) && abs(l-w)>=2) {
			printf("%d:%d\n", w, l);
			w = l = 0;
		}
	}
	printf("%d:%d\n", w, l);
	printf("\n");
	w = l = 0;
	for(i=0;i<len;i++) {
		if(A[i]=='W') w++;
		else l++;
		if((w>=21 || l>=21) && abs(l-w)>=2) {
			printf("%d:%d\n", w, l);
			w = l = 0;
		}
	}
	printf("%d:%d\n", w, l);
	return 0;
} 
