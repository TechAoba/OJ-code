#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int num=0;
char A[10000], B[10000];

int main()
{
	scanf("%s %s", A, B);
	int len = strlen(A);
	for(int i=0;i<len;i++) {
		for(int j=1;j<len;j++) {
			if(A[i]==B[j] && A[i+1]==B[j-1]) num++;
		}
	}
	printf("%d\n", 1<<num);
	return 0;
}
